// simple_server.cpp
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h> 
#include <cstring>
#include <string>

int main() {
    // Create socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        std::cerr << "Failed to create socket" << std::endl;
        return 1;
    }

    // Set socket options
    int opt = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // Define server address
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);  // Port 8080

    // Bind socket to address
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        std::cerr << "Bind failed" << std::endl;
        return 1;
    }

    // Start listening
    if (listen(server_fd, 5) < 0) {  // Backlog of 5 connections
        std::cerr << "Listen failed" << std::endl;
        return 1;
    }

    std::cout << "Server listening on http://localhost:8080" << std::endl;
    std::cout << "Press Ctrl+C to stop the server" << std::endl;

    // Main server loop
    while (true) {
        // Accept incoming connection
        int client_socket = accept(server_fd, nullptr, nullptr);
        if (client_socket < 0) {
            std::cerr << "Accept failed" << std::endl;
            continue;
        }

        // Read request (simplified - just read some bytes)
        char buffer[1024] = {0};
        read(client_socket, buffer, sizeof(buffer) - 1);
        
        std::cout << "Received request:\n" << buffer << std::endl;

        // Simple HTTP response
        std::string response = 
            "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/html\r\n"
            "Connection: close\r\n"
            "\r\n"
            "<!DOCTYPE html>"
            "<html>"
            "<head><title>C++ Server</title></head>"
            "<body>"
            "<h1>Hello from C++ Server!</h1>"
            "<p>This server is written in C++</p>"
            "<p>Current time: " + std::to_string(time(nullptr)) + "</p>"
            "</body>"
            "</html>";

        // Send response
        send(client_socket, response.c_str(), response.length(), 0);
        
        // Close connection
        close(client_socket);
        
        std::cout << "Response sent to client" << std::endl;
    }

    close(server_fd);
    return 0;
}