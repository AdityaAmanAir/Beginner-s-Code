#include <iostream>
#include <fstream>
#include <sstream>
#include <thread>
#include <chrono>
#include <atomic>
#include <vector>
#include <string>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>
#include <csignal>
#include <mutex>
#include <map>
#include <filesystem>
#include <dirent.h>
#include <libevdev-1.0/libevdev/libevdev.h>
#include <fcntl.h>
#include <linux/input.h>

namespace fs = std::filesystem;

class KeyboardServer {
private:
    std::atomic<bool> running;
    std::string keyboardBuffer;
    std::mutex bufferMutex;
    int serverSocket;
    std::map<int, std::string> keyMap;
    std::vector<int> keyboardFds;
    
public:
    KeyboardServer() : running(true) {
        keyboardBuffer = "🎮 SYSTEM-WIDE Keyboard Stream Server (evdev)\n";
        keyboardBuffer += "=============================================\n";
        keyboardBuffer += "Capturing ALL keyboard input from ANY device!\n";
        keyboardBuffer += "Access at: http://localhost:8080\n";
        keyboardBuffer += "Press Ctrl+C in terminal to stop\n\n";
        serverSocket = -1;
        
        // Initialize key mappings for Linux input event codes
        initializeKeyMap();
    }
    
    ~KeyboardServer() {
        stop();
        // Close all keyboard file descriptors
        for (int fd : keyboardFds) {
            close(fd);
        }
    }
    
    void initializeKeyMap() {
        // Standard keyboard keys (from linux/input-event-codes.h)
        keyMap[KEY_ESC] = "[ESC]";
        keyMap[KEY_1] = "1";
        keyMap[KEY_2] = "2";
        keyMap[KEY_3] = "3";
        keyMap[KEY_4] = "4";
        keyMap[KEY_5] = "5";
        keyMap[KEY_6] = "6";
        keyMap[KEY_7] = "7";
        keyMap[KEY_8] = "8";
        keyMap[KEY_9] = "9";
        keyMap[KEY_0] = "0";
        keyMap[KEY_MINUS] = "-";
        keyMap[KEY_EQUAL] = "=";
        keyMap[KEY_BACKSPACE] = "[BACKSPACE]";
        keyMap[KEY_TAB] = "[TAB]";
        keyMap[KEY_Q] = "Q";
        keyMap[KEY_W] = "W";
        keyMap[KEY_E] = "E";
        keyMap[KEY_R] = "R";
        keyMap[KEY_T] = "T";
        keyMap[KEY_Y] = "Y";
        keyMap[KEY_U] = "U";
        keyMap[KEY_I] = "I";
        keyMap[KEY_O] = "O";
        keyMap[KEY_P] = "P";
        keyMap[KEY_LEFTBRACE] = "[";
        keyMap[KEY_RIGHTBRACE] = "]";
        keyMap[KEY_ENTER] = "[ENTER]";
        keyMap[KEY_LEFTCTRL] = "[CTRL]";
        keyMap[KEY_A] = "A";
        keyMap[KEY_S] = "S";
        keyMap[KEY_D] = "D";
        keyMap[KEY_F] = "F";
        keyMap[KEY_G] = "G";
        keyMap[KEY_H] = "H";
        keyMap[KEY_J] = "J";
        keyMap[KEY_K] = "K";
        keyMap[KEY_L] = "L";
        keyMap[KEY_SEMICOLON] = ";";
        keyMap[KEY_APOSTROPHE] = "'";
        keyMap[KEY_GRAVE] = "`";
        keyMap[KEY_LEFTSHIFT] = "[SHIFT]";
        keyMap[KEY_BACKSLASH] = "\\";
        keyMap[KEY_Z] = "Z";
        keyMap[KEY_X] = "X";
        keyMap[KEY_C] = "C";
        keyMap[KEY_V] = "V";
        keyMap[KEY_B] = "B";
        keyMap[KEY_N] = "N";
        keyMap[KEY_M] = "M";
        keyMap[KEY_COMMA] = ",";
        keyMap[KEY_DOT] = ".";
        keyMap[KEY_SLASH] = "/";
        keyMap[KEY_RIGHTSHIFT] = "[SHIFT]";
        keyMap[KEY_KPASTERISK] = "*";
        keyMap[KEY_LEFTALT] = "[ALT]";
        keyMap[KEY_SPACE] = "[SPACE]";
        keyMap[KEY_CAPSLOCK] = "[CAPS_LOCK]";
        keyMap[KEY_F1] = "[F1]";
        keyMap[KEY_F2] = "[F2]";
        keyMap[KEY_F3] = "[F3]";
        keyMap[KEY_F4] = "[F4]";
        keyMap[KEY_F5] = "[F5]";
        keyMap[KEY_F6] = "[F6]";
        keyMap[KEY_F7] = "[F7]";
        keyMap[KEY_F8] = "[F8]";
        keyMap[KEY_F9] = "[F9]";
        keyMap[KEY_F10] = "[F10]";
        keyMap[KEY_F11] = "[F11]";
        keyMap[KEY_F12] = "[F12]";
        keyMap[KEY_RIGHTCTRL] = "[CTRL]";
        keyMap[KEY_RIGHTALT] = "[ALT]";
        keyMap[KEY_HOME] = "[HOME]";
        keyMap[KEY_UP] = "[UP]";
        keyMap[KEY_PAGEUP] = "[PAGE_UP]";
        keyMap[KEY_LEFT] = "[LEFT]";
        keyMap[KEY_RIGHT] = "[RIGHT]";
        keyMap[KEY_END] = "[END]";
        keyMap[KEY_DOWN] = "[DOWN]";
        keyMap[KEY_PAGEDOWN] = "[PAGE_DOWN]";
        keyMap[KEY_INSERT] = "[INSERT]";
        keyMap[KEY_DELETE] = "[DELETE]";
        keyMap[KEY_LEFTMETA] = "[SUPER]";  // Windows key
        keyMap[KEY_RIGHTMETA] = "[SUPER]"; // Windows key
    }
    
    std::string getKeyName(int keycode) {
        auto it = keyMap.find(keycode);
        if (it != keyMap.end()) {
            return it->second;
        }
        
        // Unknown key
        std::stringstream ss;
        ss << "[KEY_" << keycode << "]";
        return ss.str();
    }
    
    bool findKeyboardDevices() {
        std::cout << "🔍 Searching for keyboard devices..." << std::endl;
        
        const std::string inputDir = "/dev/input/";
        DIR* dir = opendir(inputDir.c_str());
        if (!dir) {
            std::cerr << "❌ Cannot open /dev/input directory" << std::endl;
            return false;
        }
        
        struct dirent* entry;
        int deviceCount = 0;
        
        while ((entry = readdir(dir)) != nullptr) {
            std::string filename = entry->d_name;
            
            // Look for event devices (event*)
            if (filename.find("event") == 0) {
                std::string fullPath = inputDir + filename;
                
                // Try to open the device
                int fd = open(fullPath.c_str(), O_RDONLY | O_NONBLOCK);
                if (fd < 0) {
                    continue;
                }
                
                // Create evdev context
                struct libevdev* dev = nullptr;
                int rc = libevdev_new_from_fd(fd, &dev);
                if (rc < 0) {
                    close(fd);
                    continue;
                }
                
                // Check if it has keyboard capabilities
                if (libevdev_has_event_type(dev, EV_KEY) &&
                    (libevdev_has_event_code(dev, EV_KEY, KEY_A) ||
                     libevdev_has_event_code(dev, EV_KEY, KEY_SPACE) ||
                     libevdev_has_event_code(dev, EV_KEY, KEY_ENTER))) {
                    
                    std::cout << "✅ Found keyboard: " << libevdev_get_name(dev) 
                              << " (" << filename << ")" << std::endl;
                    
                    keyboardFds.push_back(fd);
                    deviceCount++;
                    
                    // Don't free dev here, we keep the fd open
                } else {
                    libevdev_free(dev);
                    close(fd);
                }
            }
        }
        
        closedir(dir);
        
        if (deviceCount == 0) {
            std::cerr << "❌ No keyboard devices found!" << std::endl;
            std::cerr << "💡 Try running with: sudo ./keyboard_stream" << std::endl;
            return false;
        }
        
        std::cout << "🎯 Found " << deviceCount << " keyboard device(s)" << std::endl;
        return true;
    }
    
    bool startServer() {
        // Create socket
        serverSocket = socket(AF_INET, SOCK_STREAM, 0);
        if (serverSocket < 0) {
            std::cerr << "Error creating socket" << std::endl;
            return false;
        }
        
        // Set socket options
        int opt = 1;
        if (setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
            std::cerr << "Error setting socket options" << std::endl;
            return false;
        }
        
        // Bind socket
        struct sockaddr_in serverAddr;
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_addr.s_addr = INADDR_ANY;
        serverAddr.sin_port = htons(8080);
        
        if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
            std::cerr << "Error binding socket to port 8080" << std::endl;
            return false;
        }
        
        // Listen for connections
        if (listen(serverSocket, 5) < 0) {
            std::cerr << "Error listening on socket" << std::endl;
            return false;
        }
        
        std::cout << "\n===============================================" << std::endl;
        std::cout << "   SYSTEM-WIDE KEYBOARD STREAM SERVER (evdev)" << std::endl;
        std::cout << "===============================================" << std::endl;
        std::cout << "✅ Server started on port 8080" << std::endl;
        std::cout << "🌐 Access at: http://localhost:8080" << std::endl;
        std::cout << "🎮 Capturing input from ALL keyboard devices" << std::endl;
        std::cout << "🚫 Press Ctrl+C in this terminal to stop" << std::endl;
        std::cout << "===============================================\n" << std::endl;
        
        return true;
    }
    
    void addKeyEvent(const std::string& keyName, bool isPress, const std::string& deviceName = "") {
        std::lock_guard<std::mutex> lock(bufferMutex);
        
        // Get current time with milliseconds
        auto now = std::chrono::system_clock::now();
        auto now_time_t = std::chrono::system_clock::to_time_t(now);
        auto now_ms = std::chrono::duration_cast<std::chrono::milliseconds>(
            now.time_since_epoch()) % 1000;
        
        std::tm* local_time = std::localtime(&now_time_t);
        
        char timeStr[50];
        std::strftime(timeStr, sizeof(timeStr), "%H:%M:%S", local_time);
        
        std::stringstream ss;
        ss << "[" << timeStr << "." << std::setfill('0') << std::setw(3) << now_ms.count() << "] ";
        
        if (!deviceName.empty()) {
            ss << "[" << deviceName << "] ";
        }
        
        if (isPress) {
            ss << "PRESS: ";
        } else {
            ss << "RELEASE: ";
        }
        
        ss << keyName << "\n";
        
        keyboardBuffer += ss.str();
        
        // Print to console with color
        std::cout << "\033[1;36m" << timeStr << "." << std::setfill('0') << std::setw(3) << now_ms.count() 
                  << "\033[0m " << (deviceName.empty() ? "" : "[" + deviceName + "] ")
                  << (isPress ? "\033[1;32mPRESS\033[0m" : "\033[1;31mRELEASE\033[0m") 
                  << ": \033[1;33m" << keyName << "\033[0m" << std::endl;
        
        // Keep buffer size manageable
        if (keyboardBuffer.length() > 20000) {
            keyboardBuffer = keyboardBuffer.substr(keyboardBuffer.length() - 10000);
        }
    }
    
    // Rest of the HTTP handling methods remain the same as before
    void handleClient(int clientSocket) {
        std::string response = "HTTP/1.1 200 OK\r\n";
        response += "Content-Type: text/html; charset=utf-8\r\n";
        response += "Connection: close\r\n";
        response += "Access-Control-Allow-Origin: *\r\n";
        response += "\r\n";
        
        // HTML page (simplified version from previous code)
        std::string html = R"(
<!DOCTYPE html>
<html>
<head>
    <title>System-wide Keyboard Stream</title>
    <meta charset="UTF-8">
    <style>
        body { font-family: Arial, sans-serif; margin: 40px; background: #f0f0f0; }
        .container { max-width: 800px; margin: 0 auto; background: white; padding: 20px; border-radius: 10px; box-shadow: 0 2px 10px rgba(0,0,0,0.1); }
        h1 { color: #333; }
        #stream { background: #000; color: #0f0; padding: 20px; border-radius: 5px; font-family: monospace; min-height: 400px; max-height: 500px; overflow-y: auto; white-space: pre-wrap; margin: 20px 0; }
        .info { background: #e3f2fd; padding: 10px; border-radius: 5px; margin: 10px 0; }
        .timestamp { color: #888; font-size: 0.9em; }
    </style>
</head>
<body>
    <div class="container">
        <h1>🌐 System-wide Keyboard Stream (evdev)</h1>
        <div class="info">
            <p>🎮 Capturing ALL keyboard input from ANY device!</p>
            <p>🔧 Using Linux evdev interface for system-wide access</p>
            <p>⌨️ Type anywhere (VS Code, browser, terminal, etc.)</p>
            <p>🌐 Refresh this page to see updates. Running on port 8080.</p>
        </div>
        <div id="stream">Loading...</div>
        <div class="timestamp" id="timestamp"></div>
    </div>

    <script>
        function updateStream() {
            fetch('/stream')
                .then(response => response.text())
                .then(data => {
                    document.getElementById('stream').textContent = data;
                    var elem = document.getElementById('stream');
                    elem.scrollTop = elem.scrollHeight;
                })
                .catch(error => console.error('Error:', error));
        }
        
        function updateTime() {
            var now = new Date();
            document.getElementById('timestamp').textContent = 'Last updated: ' + now.toLocaleTimeString();
        }
        
        setInterval(updateStream, 100);
        setInterval(updateTime, 1000);
        updateStream();
        updateTime();
    </script>
</body>
</html>
        )";
        
        response += html;
        send(clientSocket, response.c_str(), response.length(), 0);
        close(clientSocket);
    }
    
    void handleStreamRequest(int clientSocket) {
        std::lock_guard<std::mutex> lock(bufferMutex);
        
        std::string response = "HTTP/1.1 200 OK\r\n";
        response += "Content-Type: text/plain; charset=utf-8\r\n";
        response += "Cache-Control: no-cache\r\n";
        response += "Access-Control-Allow-Origin: *\r\n";
        response += "\r\n";
        response += keyboardBuffer;
        
        send(clientSocket, response.c_str(), response.length(), 0);
        close(clientSocket);
    }
    
    void runServer() {
        while (running) {
            fd_set readfds;
            FD_ZERO(&readfds);
            FD_SET(serverSocket, &readfds);
            
            struct timeval tv;
            tv.tv_sec = 0;
            tv.tv_usec = 100000; // 100ms timeout
            
            int activity = select(serverSocket + 1, &readfds, NULL, NULL, &tv);
            
            if (activity > 0 && FD_ISSET(serverSocket, &readfds)) {
                struct sockaddr_in clientAddr;
                socklen_t clientLen = sizeof(clientAddr);
                
                int clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &clientLen);
                if (clientSocket >= 0) {
                    char buffer[1024] = {0};
                    recv(clientSocket, buffer, sizeof(buffer) - 1, 0);
                    
                    if (strstr(buffer, "GET /stream ")) {
                        handleStreamRequest(clientSocket);
                    } else {
                        handleClient(clientSocket);
                    }
                }
            }
            
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
    }
    
    void stop() {
        running = false;
        if (serverSocket >= 0) {
            close(serverSocket);
            serverSocket = -1;
        }
    }
    
    bool isRunning() const {
        return running;
    }
    
    void monitorKeyboards() {
        std::vector<libevdev*> devices;
        
        // Open all keyboard devices
        for (int fd : keyboardFds) {
            libevdev* dev = nullptr;
            int rc = libevdev_new_from_fd(fd, &dev);
            if (rc >= 0) {
                devices.push_back(dev);
                std::cout << "👂 Listening to: " << libevdev_get_name(dev) << std::endl;
            }
        }
        
        if (devices.empty()) {
            std::cerr << "❌ No keyboard devices opened!" << std::endl;
            return;
        }
        
        std::cout << "\n🎯 Now capturing keys from ALL connected keyboards..." << std::endl;
        std::cout << "💡 Press keys in ANY application (VS Code, browser, etc.)" << std::endl;
        std::cout << "🚫 Press Ctrl+C in this terminal to stop\n" << std::endl;
        
        while (running) {
            for (size_t i = 0; i < devices.size(); i++) {
                libevdev* dev = devices[i];
                int fd = keyboardFds[i];
                
                struct input_event ev;
                int rc = libevdev_next_event(dev, LIBEVDEV_READ_FLAG_NORMAL, &ev);
                
                if (rc == 0) {
                    if (ev.type == EV_KEY) {
                        std::string keyName = getKeyName(ev.code);
                        std::string deviceName = libevdev_get_name(dev);
                        
                        if (ev.value == 1) { // Key press
                            addKeyEvent(keyName, true, deviceName);
                        } else if (ev.value == 0) { // Key release
                            addKeyEvent(keyName, false, deviceName);
                        }
                    }
                }
            }
            
            // Small delay to prevent CPU spinning
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
        
        // Cleanup
        for (libevdev* dev : devices) {
            libevdev_free(dev);
        }
    }
};

void signalHandler(int signum) {
    std::cout << "\n🛑 Interrupt signal received. Stopping..." << std::endl;
    exit(signum);
}

int main() {
    // Set up signal handler for Ctrl+C
    signal(SIGINT, signalHandler);
    
    std::cout << "\033[1;36m" << "===============================================" << "\033[0m" << std::endl;
    std::cout << "\033[1;35m" << "   SYSTEM-WIDE KEYBOARD STREAM (evdev) v2.0" << "\033[0m" << std::endl;
    std::cout << "\033[1;36m" << "===============================================\n" << "\033[0m" << std::endl;
    
    KeyboardServer server;
    
    // First, find and open keyboard devices
    if (!server.findKeyboardDevices()) {
        std::cerr << "❌ Failed to find keyboard devices!" << std::endl;
        return 1;
    }
    
    // Start the web server
    if (!server.startServer()) {
        std::cerr << "❌ Failed to start server!" << std::endl;
        return 1;
    }
    
    // Start keyboard monitoring in separate thread
    std::thread keyboardThread(&KeyboardServer::monitorKeyboards, &server);
    
    // Run server in main thread
    server.runServer();
    
    // Wait for keyboard thread to finish
    keyboardThread.join();
    
    std::cout << "\n✅ Server stopped successfully!" << std::endl;
    return 0;
}