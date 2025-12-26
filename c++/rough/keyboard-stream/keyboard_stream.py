#!/usr/bin/env python3
"""
System-wide Keyboard Stream Server - PASSIVE VERSION
Captures ALL keyboard input WITHOUT interfering with normal typing
Run with: sudo ./keyboard_stream.py
"""

import os
import sys
import threading
import time
from datetime import datetime
import select
from http.server import HTTPServer, BaseHTTPRequestHandler
import socket

# Add virtual environment path
import glob
venv_path = os.path.join(os.path.dirname(__file__), 'keyboard_env', 'lib', 'python3.*', 'site-packages')
venv_site_packages = glob.glob(venv_path)[0] if glob.glob(venv_path) else None

if venv_site_packages and venv_site_packages not in sys.path:
    sys.path.insert(0, venv_site_packages)

try:
    from evdev import InputDevice, ecodes, list_devices, InputEvent
    HAS_EVDEV = True
except ImportError:
    print("❌ evdev not found. Make sure virtual environment is activated.")
    print("💡 Run: source keyboard_env/bin/activate && pip install evdev")
    HAS_EVDEV = False

class KeyboardHandler:
    """Handles keyboard input capture WITHOUT grabbing/blocking"""
    
    def __init__(self):
        self.key_log = []
        self.key_log_lock = threading.Lock()
        self.running = True
        self.keyboards = []
        self.pressed_keys = set()  # Track currently pressed keys
        
        # Key mappings - expanded for better coverage
        self.key_map = self._create_key_map()
    
    def _create_key_map(self):
        """Create comprehensive key mapping"""
        key_map = {
            # Main keyboard keys
            ecodes.KEY_ESC: "[ESC]",
            ecodes.KEY_1: "1", ecodes.KEY_2: "2", ecodes.KEY_3: "3",
            ecodes.KEY_4: "4", ecodes.KEY_5: "5", ecodes.KEY_6: "6",
            ecodes.KEY_7: "7", ecodes.KEY_8: "8", ecodes.KEY_9: "9",
            ecodes.KEY_0: "0",
            ecodes.KEY_MINUS: "-", ecodes.KEY_EQUAL: "=",
            ecodes.KEY_BACKSPACE: "[BACKSPACE]",
            ecodes.KEY_TAB: "[TAB]",
            ecodes.KEY_Q: "q", ecodes.KEY_W: "w", ecodes.KEY_E: "e",
            ecodes.KEY_R: "r", ecodes.KEY_T: "t", ecodes.KEY_Y: "y",
            ecodes.KEY_U: "u", ecodes.KEY_I: "i", ecodes.KEY_O: "o",
            ecodes.KEY_P: "p",
            ecodes.KEY_LEFTBRACE: "[", ecodes.KEY_RIGHTBRACE: "]",
            ecodes.KEY_ENTER: "[ENTER]",
            ecodes.KEY_LEFTCTRL: "[CTRL]",
            ecodes.KEY_A: "a", ecodes.KEY_S: "s", ecodes.KEY_D: "d",
            ecodes.KEY_F: "f", ecodes.KEY_G: "g", ecodes.KEY_H: "h",
            ecodes.KEY_J: "j", ecodes.KEY_K: "k", ecodes.KEY_L: "l",
            ecodes.KEY_SEMICOLON: ";", ecodes.KEY_APOSTROPHE: "'",
            ecodes.KEY_GRAVE: "`",
            ecodes.KEY_LEFTSHIFT: "[SHIFT]",
            ecodes.KEY_BACKSLASH: "\\",
            ecodes.KEY_Z: "z", ecodes.KEY_X: "x", ecodes.KEY_C: "c",
            ecodes.KEY_V: "v", ecodes.KEY_B: "b", ecodes.KEY_N: "n",
            ecodes.KEY_M: "m",
            ecodes.KEY_COMMA: ",", ecodes.KEY_DOT: ".", ecodes.KEY_SLASH: "/",
            ecodes.KEY_RIGHTSHIFT: "[SHIFT]",
            ecodes.KEY_KPASTERISK: "*",
            ecodes.KEY_LEFTALT: "[ALT]",
            ecodes.KEY_SPACE: "[SPACE]",
            ecodes.KEY_CAPSLOCK: "[CAPS_LOCK]",
            
            # Function keys
            ecodes.KEY_F1: "[F1]", ecodes.KEY_F2: "[F2]", ecodes.KEY_F3: "[F3]",
            ecodes.KEY_F4: "[F4]", ecodes.KEY_F5: "[F5]", ecodes.KEY_F6: "[F6]",
            ecodes.KEY_F7: "[F7]", ecodes.KEY_F8: "[F8]", ecodes.KEY_F9: "[F9]",
            ecodes.KEY_F10: "[F10]", ecodes.KEY_F11: "[F11]", ecodes.KEY_F12: "[F12]",
            
            # Navigation keys
            ecodes.KEY_HOME: "[HOME]",
            ecodes.KEY_UP: "[UP]",
            ecodes.KEY_PAGEUP: "[PAGE_UP]",
            ecodes.KEY_LEFT: "[LEFT]",
            ecodes.KEY_RIGHT: "[RIGHT]",
            ecodes.KEY_END: "[END]",
            ecodes.KEY_DOWN: "[DOWN]",
            ecodes.KEY_PAGEDOWN: "[PAGE_DOWN]",
            ecodes.KEY_INSERT: "[INSERT]",
            ecodes.KEY_DELETE: "[DELETE]",
            
            # Special keys
            ecodes.KEY_LEFTMETA: "[SUPER]",  # Windows key
            ecodes.KEY_RIGHTMETA: "[SUPER]",
            ecodes.KEY_COMPOSE: "[COMPOSE]",
            ecodes.KEY_PRINT: "[PRINT]",
            ecodes.KEY_SCROLLLOCK: "[SCROLL_LOCK]",
            ecodes.KEY_PAUSE: "[PAUSE]",
            ecodes.KEY_NUMLOCK: "[NUM_LOCK]",
            
            # Numpad keys
            ecodes.KEY_KP0: "0", ecodes.KEY_KP1: "1", ecodes.KEY_KP2: "2",
            ecodes.KEY_KP3: "3", ecodes.KEY_KP4: "4", ecodes.KEY_KP5: "5",
            ecodes.KEY_KP6: "6", ecodes.KEY_KP7: "7", ecodes.KEY_KP8: "8",
            ecodes.KEY_KP9: "9",
            ecodes.KEY_KPDOT: ".", ecodes.KEY_KPENTER: "[ENTER]",
            ecodes.KEY_KPPLUS: "+", ecodes.KEY_KPMINUS: "-",
            ecodes.KEY_KPASTERISK: "*", ecodes.KEY_KPSLASH: "/",
        }
        
        # Add uppercase versions when shift is pressed
        shift_key_map = {
            ecodes.KEY_A: "A", ecodes.KEY_B: "B", ecodes.KEY_C: "C",
            ecodes.KEY_D: "D", ecodes.KEY_E: "E", ecodes.KEY_F: "F",
            ecodes.KEY_G: "G", ecodes.KEY_H: "H", ecodes.KEY_I: "I",
            ecodes.KEY_J: "J", ecodes.KEY_K: "K", ecodes.KEY_L: "L",
            ecodes.KEY_M: "M", ecodes.KEY_N: "N", ecodes.KEY_O: "O",
            ecodes.KEY_P: "P", ecodes.KEY_Q: "Q", ecodes.KEY_R: "R",
            ecodes.KEY_S: "S", ecodes.KEY_T: "T", ecodes.KEY_U: "U",
            ecodes.KEY_V: "V", ecodes.KEY_W: "W", ecodes.KEY_X: "X",
            ecodes.KEY_Y: "Y", ecodes.KEY_Z: "Z",
            ecodes.KEY_1: "!", ecodes.KEY_2: "@", ecodes.KEY_3: "#",
            ecodes.KEY_4: "$", ecodes.KEY_5: "%", ecodes.KEY_6: "^",
            ecodes.KEY_7: "&", ecodes.KEY_8: "*", ecodes.KEY_9: "(",
            ecodes.KEY_0: ")", ecodes.KEY_GRAVE: "~",
            ecodes.KEY_MINUS: "_", ecodes.KEY_EQUAL: "+",
            ecodes.KEY_LEFTBRACE: "{", ecodes.KEY_RIGHTBRACE: "}",
            ecodes.KEY_BACKSLASH: "|", ecodes.KEY_SEMICOLON: ":",
            ecodes.KEY_APOSTROPHE: '"', ecodes.KEY_COMMA: "<",
            ecodes.KEY_DOT: ">", ecodes.KEY_SLASH: "?",
        }
        
        # Store both regular and shift versions
        self.shift_key_map = shift_key_map
        return key_map
    
    def get_key_name(self, keycode, shift_pressed=False, caps_lock=False):
        """Convert keycode to readable name, considering shift and caps lock"""
        # Default mapping
        key_name = self.key_map.get(keycode, f"[KEY_{keycode}]")
        
        # Check if shift changes the key
        if shift_pressed and keycode in self.shift_key_map:
            return self.shift_key_map[keycode]
        
        # Handle caps lock for letters
        if caps_lock and keycode in range(ecodes.KEY_A, ecodes.KEY_Z + 1):
            return key_name.upper() if key_name.isalpha() and key_name.islower() else key_name
        
        # Handle shift + caps lock combination
        if shift_pressed and caps_lock and keycode in range(ecodes.KEY_A, ecodes.KEY_Z + 1):
            return key_name.lower() if key_name.isalpha() and key_name.isupper() else key_name
        
        return key_name
    
    def find_keyboards(self):
        """Find all keyboard devices"""
        print("🔍 Searching for keyboard devices...")
        
        try:
            device_paths = list_devices()
            if not device_paths:
                print("❌ No input devices found!")
                return False
            
            for path in device_paths:
                try:
                    device = InputDevice(path)
                    # Check if it's a keyboard by looking for common keys
                    caps = device.capabilities()
                    if ecodes.EV_KEY in caps:
                        key_codes = caps[ecodes.EV_KEY]
                        # Check if it has typical keyboard keys
                        if (ecodes.KEY_A in key_codes or 
                            ecodes.KEY_SPACE in key_codes or 
                            ecodes.KEY_ENTER in key_codes):
                            self.keyboards.append(device)
                            print(f"✅ Found keyboard: {device.name} ({path})")
                except Exception as e:
                    continue
            
            if not self.keyboards:
                print("❌ No keyboard devices found!")
                print("💡 Make sure you have permission to access input devices")
                return False
            
            print(f"🎯 Found {len(self.keyboards)} keyboard device(s)")
            return True
            
        except Exception as e:
            print(f"❌ Error finding keyboards: {e}")
            return False
    
    def log_key_event(self, device_name, key_name, event_type, modifiers=""):
        """Log a key event with timestamp"""
        timestamp = datetime.now().strftime("%H:%M:%S.%f")[:-3]
        
        with self.key_log_lock:
            entry = f"[{timestamp}] [{device_name}] {event_type}: {modifiers}{key_name}"
            self.key_log.append(entry)
            
            # Keep only last 500 entries
            if len(self.key_log) > 500:
                self.key_log.pop(0)
        
        # Print to console with colors
        color_code = "\033[1;32m" if event_type == "PRESS" else "\033[1;31m"
        reset_code = "\033[0m"
        modifier_text = f"{modifiers}" if modifiers else ""
        print(f"\033[1;36m{timestamp}\033[0m [{device_name}] {color_code}{event_type}{reset_code}: \033[1;33m{modifier_text}{key_name}{reset_code}")
    
    def monitor_keyboard(self, device):
        """Monitor a single keyboard device WITHOUT grabbing"""
        print(f"👂 Listening to: {device.name}")
        
        try:
            # DO NOT grab the device - this allows normal typing to continue
            # device.grab()  # REMOVED THIS LINE - DON'T GRAB!
            
            # Track modifier states
            shift_pressed = False
            ctrl_pressed = False
            alt_pressed = False
            caps_lock = False
            
            # Use non-blocking mode to read events
            device.fd  # Access file descriptor
            
            while self.running:
                try:
                    # Read events with timeout
                    events = device.read()
                    if events:
                        for event in events:
                            if event.type == ecodes.EV_KEY:
                                keycode = event.code
                                
                                # Update modifier states
                                if keycode == ecodes.KEY_LEFTSHIFT or keycode == ecodes.KEY_RIGHTSHIFT:
                                    shift_pressed = (event.value == 1)
                                elif keycode == ecodes.KEY_LEFTCTRL or keycode == ecodes.KEY_RIGHTCTRL:
                                    ctrl_pressed = (event.value == 1)
                                elif keycode == ecodes.KEY_LEFTALT or keycode == ecodes.KEY_RIGHTALT:
                                    alt_pressed = (event.value == 1)
                                elif keycode == ecodes.KEY_CAPSLOCK and event.value == 1:
                                    # Toggle caps lock on press
                                    caps_lock = not caps_lock
                                
                                # Determine event type
                                if event.value == 1:  # Key press
                                    event_type = "PRESS"
                                    
                                    # Build modifier string
                                    modifiers = ""
                                    if ctrl_pressed:
                                        modifiers += "Ctrl+"
                                    if alt_pressed:
                                        modifiers += "Alt+"
                                    if shift_pressed:
                                        modifiers += "Shift+"
                                    
                                    # Get key name with modifiers
                                    key_name = self.get_key_name(keycode, shift_pressed, caps_lock)
                                    
                                    # Don't log modifier-only events (unless they're interesting)
                                    if keycode not in [ecodes.KEY_LEFTSHIFT, ecodes.KEY_RIGHTSHIFT,
                                                      ecodes.KEY_LEFTCTRL, ecodes.KEY_RIGHTCTRL,
                                                      ecodes.KEY_LEFTALT, ecodes.KEY_RIGHTALT]:
                                        self.log_key_event(device.name, key_name, event_type, modifiers)
                                    
                                    # Track pressed keys
                                    self.pressed_keys.add((device.name, keycode))
                                    
                                elif event.value == 0:  # Key release
                                    event_type = "RELEASE"
                                    
                                    # Get key name
                                    key_name = self.get_key_name(keycode, shift_pressed, caps_lock)
                                    
                                    # Don't log modifier-only releases
                                    if keycode not in [ecodes.KEY_LEFTSHIFT, ecodes.KEY_RIGHTSHIFT,
                                                      ecodes.KEY_LEFTCTRL, ecodes.KEY_RIGHTCTRL,
                                                      ecodes.KEY_LEFTALT, ecodes.KEY_RIGHTALT]:
                                        self.log_key_event(device.name, key_name, event_type)
                                    
                                    # Remove from pressed keys
                                    self.pressed_keys.discard((device.name, keycode))
                                
                                elif event.value == 2:  # Key repeat (autorepeat)
                                    # Optional: log autorepeat if you want
                                    pass
                                    
                except BlockingIOError:
                    # No data available, sleep a bit
                    time.sleep(0.001)  # 1ms
                except OSError as e:
                    # Device might have been disconnected
                    print(f"⚠️ Device {device.name} error: {e}")
                    break
                    
        except Exception as e:
            print(f"❌ Error monitoring {device.name}: {e}")
            import traceback
            traceback.print_exc()
        finally:
            try:
                # No need to ungrab since we never grabbed
                device.close()
            except:
                pass
    
    def start_monitoring(self):
        """Start monitoring all keyboards in separate threads"""
        if not self.keyboards:
            return False
        
        print(f"\n🎮 Starting PASSIVE monitoring of {len(self.keyboards)} keyboard(s)...")
        print("💡 IMPORTANT: Keyboard is NOT grabbed - you can type normally!")
        
        # Start a thread for each keyboard
        self.threads = []
        for keyboard in self.keyboards:
            thread = threading.Thread(target=self.monitor_keyboard, args=(keyboard,))
            thread.daemon = True
            thread.start()
            self.threads.append(thread)
        
        print("✅ Keyboard monitoring started!")
        print("💡 Type ANYWHERE (VS Code, browser, terminal) - it will work normally")
        print("📡 Keys will be captured WITHOUT blocking normal input")
        print("🌐 View stream at: http://localhost:8080")
        print("🚫 Press Ctrl+C to stop\n")
        return True
    
    def stop(self):
        """Stop monitoring"""
        self.running = False
        for keyboard in self.keyboards:
            try:
                keyboard.close()
            except:
                pass
    
    def get_log(self):
        """Get the current key log"""
        with self.key_log_lock:
            return "\n".join(self.key_log)
    
    def clear_log(self):
        """Clear the key log"""
        with self.key_log_lock:
            self.key_log.clear()
            self.log_key_event("System", "Log cleared", "INFO")

class WebServer(BaseHTTPRequestHandler):
    """Simple HTTP server to serve the keyboard stream"""
    
    keyboard_handler = None  # Will be set by main
    
    def do_GET(self):
        """Handle GET requests"""
        if self.path == '/':
            self.send_html()
        elif self.path == '/stream':
            self.send_stream()
        elif self.path == '/clear':
            self.clear_stream()
        elif self.path == '/status':
            self.send_status()
        else:
            self.send_error(404)
    
    def send_html(self):
        """Send the HTML interface"""
        html = """<!DOCTYPE html>
<html>
<head>
    <title>Passive Keyboard Stream</title>
    <meta charset="UTF-8">
    <style>
        * { margin: 0; padding: 0; box-sizing: border-box; }
        body {
            font-family: 'Segoe UI', Ubuntu, sans-serif;
            background: linear-gradient(135deg, #1a1a2e, #16213e, #0f3460);
            color: white;
            min-height: 100vh;
            padding: 20px;
        }
        .container {
            max-width: 1200px;
            margin: 0 auto;
            background: rgba(255, 255, 255, 0.05);
            backdrop-filter: blur(10px);
            border-radius: 20px;
            overflow: hidden;
            box-shadow: 0 20px 40px rgba(0, 0, 0, 0.4);
            border: 1px solid rgba(255, 255, 255, 0.1);
        }
        .header {
            background: linear-gradient(135deg, #00b4db, #0083b0);
            padding: 30px;
            text-align: center;
            position: relative;
            overflow: hidden;
        }
        .header::before {
            content: '⌨️';
            position: absolute;
            font-size: 150px;
            opacity: 0.1;
            right: -30px;
            top: -30px;
            transform: rotate(15deg);
        }
        h1 {
            font-size: 2.8em;
            margin-bottom: 10px;
            position: relative;
        }
        .subtitle {
            font-size: 1.2em;
            opacity: 0.9;
            margin-bottom: 15px;
        }
        .status-badge {
            display: inline-block;
            background: rgba(255, 255, 255, 0.2);
            padding: 8px 20px;
            border-radius: 20px;
            font-size: 0.9em;
        }
        .info-box {
            background: rgba(0, 0, 0, 0.3);
            padding: 25px;
            margin: 25px;
            border-radius: 15px;
            border-left: 5px solid #00b4db;
        }
        .info-box h3 {
            color: #00b4db;
            margin-bottom: 15px;
            display: flex;
            align-items: center;
            gap: 10px;
        }
        .feature-list {
            display: grid;
            grid-template-columns: repeat(auto-fit, minmax(300px, 1fr));
            gap: 15px;
            margin-top: 15px;
        }
        .feature {
            background: rgba(255, 255, 255, 0.05);
            padding: 15px;
            border-radius: 10px;
            display: flex;
            align-items: center;
            gap: 12px;
        }
        .feature-icon {
            font-size: 1.5em;
        }
        #stream {
            background: rgba(0, 0, 0, 0.8);
            color: #81e6d9;
            font-family: 'Fira Code', 'Ubuntu Mono', monospace;
            font-size: 1.1em;
            padding: 30px;
            margin: 25px;
            border-radius: 15px;
            min-height: 500px;
            max-height: 600px;
            overflow-y: auto;
            white-space: pre-wrap;
            word-wrap: break-word;
            border: 2px solid rgba(0, 180, 219, 0.3);
            box-shadow: inset 0 0 20px rgba(0, 0, 0, 0.5);
            line-height: 1.6;
        }
        .controls {
            display: flex;
            justify-content: center;
            gap: 15px;
            margin: 25px;
            flex-wrap: wrap;
        }
        button {
            background: linear-gradient(135deg, #00b4db, #0083b0);
            color: white;
            border: none;
            padding: 14px 28px;
            border-radius: 10px;
            cursor: pointer;
            font-size: 1em;
            font-weight: bold;
            transition: all 0.3s ease;
            display: flex;
            align-items: center;
            gap: 10px;
            min-width: 180px;
            justify-content: center;
        }
        button:hover {
            transform: translateY(-3px);
            box-shadow: 0 10px 20px rgba(0, 180, 219, 0.3);
        }
        button:active {
            transform: translateY(-1px);
        }
        .stats {
            display: flex;
            justify-content: space-around;
            padding: 20px;
            background: rgba(0, 0, 0, 0.2);
            margin: 25px;
            border-radius: 15px;
            flex-wrap: wrap;
            gap: 20px;
        }
        .stat {
            text-align: center;
            padding: 15px;
            min-width: 150px;
        }
        .stat-value {
            font-size: 2.2em;
            font-weight: bold;
            color: #00b4db;
            display: block;
        }
        .stat-label {
            font-size: 0.9em;
            opacity: 0.8;
            margin-top: 5px;
        }
        
        /* Key styling */
        .press { color: #4ecdc4; }
        .release { color: #ff6b6b; }
        .info { color: #ffa500; }
        .time { color: #888; font-size: 0.9em; }
        .key { color: #ffd93d; font-weight: bold; }
        .modifier { color: #00b4db; }
        
        /* Scrollbar */
        #stream::-webkit-scrollbar { width: 12px; }
        #stream::-webkit-scrollbar-track { background: rgba(0, 0, 0, 0.3); border-radius: 6px; }
        #stream::-webkit-scrollbar-thumb { 
            background: linear-gradient(135deg, #00b4db, #0083b0); 
            border-radius: 6px; 
            border: 3px solid rgba(0, 0, 0, 0.3);
        }
        
        @keyframes pulse { 
            0% { opacity: 1; } 
            50% { opacity: 0.5; } 
            100% { opacity: 1; } 
        }
        .live-indicator {
            display: inline-flex;
            align-items: center;
            gap: 8px;
            animation: pulse 2s infinite;
        }
        .live-dot {
            width: 12px;
            height: 12px;
            background: #4ecdc4;
            border-radius: 50%;
        }
        
        .footer {
            text-align: center;
            padding: 20px;
            color: rgba(255, 255, 255, 0.6);
            font-size: 0.9em;
            border-top: 1px solid rgba(255, 255, 255, 0.1);
        }
        
        @media (max-width: 768px) {
            .container { margin: 10px; }
            .controls { flex-direction: column; align-items: center; }
            button { width: 90%; }
            .feature-list { grid-template-columns: 1fr; }
        }
    </style>
</head>
<body>
    <div class="container">
        <div class="header">
            <h1>🌐 Passive Keyboard Stream</h1>
            <p class="subtitle">Capture keystrokes WITHOUT interrupting your work</p>
            <div class="status-badge">
                <span class="live-indicator">
                    <span class="live-dot"></span>
                    <span>PASSIVE MODE - Port 8080</span>
                </span>
            </div>
        </div>
        
        <div class="info-box">
            <h3>🎯 How It Works</h3>
            <div class="feature-list">
                <div class="feature">
                    <span class="feature-icon">👁️</span>
                    <div>
                        <strong>Passive Monitoring</strong>
                        <p>Only watches, doesn't interfere. Type normally anywhere!</p>
                    </div>
                </div>
                <div class="feature">
                    <span class="feature-icon">⌨️</span>
                    <div>
                        <strong>System-wide Capture</strong>
                        <p>VS Code, browsers, terminals - works everywhere</p>
                    </div>
                </div>
                <div class="feature">
                    <span class="feature-icon">🔒</span>
                    <div>
                        <strong>No Keyboard Grab</strong>
                        <p>Your typing goes where it should - this just watches</p>
                    </div>
                </div>
            </div>
        </div>
        
        <div class="stats">
            <div class="stat">
                <span class="stat-value" id="totalKeys">0</span>
                <span class="stat-label">Keys Captured</span>
            </div>
            <div class="stat">
                <span class="stat-value" id="activeTime">0s</span>
                <span class="stat-label">Active Time</span>
            </div>
            <div class="stat">
                <span class="stat-value" id="keyRate">0/s</span>
                <span class="stat-label">Key Rate</span>
            </div>
            <div class="stat">
                <span class="stat-value" id="devices">0</span>
                <span class="stat-label">Devices</span>
            </div>
        </div>
        
        <div id="stream">Starting keyboard stream...</div>
        
        <div class="controls">
            <button onclick="refreshStream()">
                🔄 Refresh Stream
            </button>
            <button onclick="clearStream()">
                🗑️ Clear Log
            </button>
            <button onclick="exportData()">
                📥 Export Data
            </button>
            <button onclick="toggleAutoRefresh()" id="autoRefreshBtn">
                ⏸️ Pause Auto-Refresh
            </button>
        </div>
        
        <div class="footer">
            <p>Passive Keyboard Stream Server | Type normally anywhere | Press Ctrl+C in terminal to stop</p>
            <p style="margin-top: 10px; font-size: 0.8em; opacity: 0.7;">
                This tool only monitors - it does NOT interfere with your typing
            </p>
        </div>
    </div>

    <script>
        let autoRefresh = true;
        let lastData = '';
        let startTime = Date.now();
        let totalKeys = 0;
        let keyTimes = [];
        
        function formatText(text) {
            return text
                .replace(/\[(\d{2}:\d{2}:\d{2}\.\d{3})\]/g, '<span class="time">[$1]</span>')
                .replace(/PRESS:/g, '<span class="press">PRESS:</span>')
                .replace(/RELEASE:/g, '<span class="release">RELEASE:</span>')
                .replace(/INFO:/g, '<span class="info">INFO:</span>')
                .replace(/Ctrl\+/g, '<span class="modifier">Ctrl</span>+')
                .replace(/Alt\+/g, '<span class="modifier">Alt</span>+')
                .replace(/Shift\+/g, '<span class="modifier">Shift</span>+')
                .replace(/: (.*?)$/gm, ': <span class="key">$1</span>');
        }
        
        function updateStats() {
            const now = Date.now();
            const activeSeconds = Math.floor((now - startTime) / 1000);
            
            // Update total keys
            const keys = document.getElementById('stream').textContent.split('\n').length;
            totalKeys = keys;
            document.getElementById('totalKeys').textContent = keys;
            
            // Update active time
            const hours = Math.floor(activeSeconds / 3600);
            const minutes = Math.floor((activeSeconds % 3600) / 60);
            const seconds = activeSeconds % 60;
            
            if (hours > 0) {
                document.getElementById('activeTime').textContent = `${hours}h ${minutes}m`;
            } else if (minutes > 0) {
                document.getElementById('activeTime').textContent = `${minutes}m ${seconds}s`;
            } else {
                document.getElementById('activeTime').textContent = `${seconds}s`;
            }
            
            // Update key rate (last 5 seconds)
            const fiveSecondsAgo = now - 5000;
            keyTimes = keyTimes.filter(time => time > fiveSecondsAgo);
            const rate = keyTimes.length / 5;
            document.getElementById('keyRate').textContent = rate.toFixed(1) + '/s';
        }
        
        function refreshStream() {
            fetch('/stream')
                .then(response => response.text())
                .then(data => {
                    if (data !== lastData) {
                        const lines = data.split('\n');
                        keyTimes.push(...Array(lines.length - (lastData.split('\n').length || 0)).fill(Date.now()));
                        
                        document.getElementById('stream').innerHTML = formatText(data);
                        const elem = document.getElementById('stream');
                        elem.scrollTop = elem.scrollHeight;
                        lastData = data;
                        
                        updateStats();
                    }
                })
                .catch(error => console.error('Error:', error));
        }
        
        function clearStream() {
            if (confirm('Are you sure you want to clear the keyboard log?')) {
                fetch('/clear')
                    .then(() => {
                        lastData = '';
                        keyTimes = [];
                        refreshStream();
                    });
            }
        }
        
        function exportData() {
            const text = document.getElementById('stream').textContent;
            const blob = new Blob([text], {type: 'text/plain'});
            const url = window.URL.createObjectURL(blob);
            const a = document.createElement('a');
            a.href = url;
            a.download = 'keyboard-stream-' + new Date().toISOString().replace(/[:.]/g, '-') + '.txt';
            document.body.appendChild(a);
            a.click();
            document.body.removeChild(a);
            window.URL.revokeObjectURL(url);
        }
        
        function toggleAutoRefresh() {
            autoRefresh = !autoRefresh;
            const btn = document.getElementById('autoRefreshBtn');
            btn.innerHTML = autoRefresh ? '⏸️ Pause Auto-Refresh' : '▶️ Resume Auto-Refresh';
        }
        
        // Get device count
        fetch('/status')
            .then(r => r.json())
            .then(data => {
                document.getElementById('devices').textContent = data.devices || 0;
            });
        
        // Auto-refresh every 200ms
        setInterval(() => {
            if (autoRefresh) refreshStream();
        }, 200);
        
        // Update stats every second
        setInterval(updateStats, 1000);
        
        // Initial refresh
        refreshStream();
        updateStats();
    </script>
</body>
</html>"""
        
        self.send_response(200)
        self.send_header('Content-Type', 'text/html; charset=utf-8')
        self.end_headers()
        self.wfile.write(html.encode('utf-8'))
    
    def send_stream(self):
        """Send the raw keyboard stream data"""
        if self.keyboard_handler:
            data = self.keyboard_handler.get_log()
            self.send_response(200)
            self.send_header('Content-Type', 'text/plain; charset=utf-8')
            self.send_header('Cache-Control', 'no-cache')
            self.end_headers()
            self.wfile.write(data.encode('utf-8'))
        else:
            self.send_error(500, "Keyboard handler not initialized")
    
    def clear_stream(self):
        """Clear the keyboard stream"""
        if self.keyboard_handler:
            self.keyboard_handler.clear_log()
            self.send_response(200)
            self.end_headers()
        else:
            self.send_error(500, "Keyboard handler not initialized")
    
    def send_status(self):
        """Send server status as JSON"""
        import json
        status = {
            "devices": len(self.keyboard_handler.keyboards) if self.keyboard_handler else 0,
            "running": True
        }
        
        self.send_response(200)
        self.send_header('Content-Type', 'application/json')
        self.end_headers()
        self.wfile.write(json.dumps(status).encode('utf-8'))
    
    def log_message(self, format, *args):
        """Disable default logging"""
        pass

def start_web_server(keyboard_handler, port=8080):
    """Start the HTTP server"""
    WebServer.keyboard_handler = keyboard_handler
    
    server = HTTPServer(('', port), WebServer)
    print(f"🌐 Web server started on port {port}")
    print(f"📱 Open: http://localhost:{port}")
    
    try:
        server.serve_forever()
    except KeyboardInterrupt:
        print("\n🛑 Web server stopping...")
    finally:
        server.server_close()

def main():
    """Main function"""
    print("\033[1;36m" + "="*70 + "\033[0m")
    print("\033[1;35m" + "   PASSIVE KEYBOARD STREAM SERVER v3.0" + "\033[0m")
    print("\033[1;36m" + "="*70 + "\033[0m")
    print("\033[1;33m" + "   Captures keystrokes WITHOUT interrupting your work!" + "\033[0m")
    print("\033[1;36m" + "="*70 + "\033[0m")
    
    # Check if running as root
    if os.geteuid() != 0:
        print("\n❌ This program MUST be run with sudo!")
        print("💡 Run: sudo ./keyboard_stream.py")
        print("\nReason: Need root access to read input devices")
        sys.exit(1)
    
    if not HAS_EVDEV:
        print("\n❌ evdev module not found!")
        print("💡 Make sure to:")
        print("   1. Create virtual environment: python3 -m venv keyboard_env")
        print("   2. Activate it: source keyboard_env/bin/activate")
        print("   3. Install: pip install evdev")
        print("   4. Run: sudo ./keyboard_stream.py")
        sys.exit(1)
    
    # Initialize keyboard handler
    kb_handler = KeyboardHandler()
    
    # Find keyboards
    if not kb_handler.find_keyboards():
        sys.exit(1)
    
    # Start keyboard monitoring in background thread
    if not kb_handler.start_monitoring():
        sys.exit(1)
    
    # Start web server in main thread
    try:
        start_web_server(kb_handler, 8080)
    except KeyboardInterrupt:
        print("\n🛑 Shutting down...")
    finally:
        kb_handler.stop()
        print("\n✅ Server stopped. Goodbye!")

if __name__ == "__main__":
    main()