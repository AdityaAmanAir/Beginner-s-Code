import socket

class UDPMessageServer:
    def __init__(self, host='localhost', port=5001):
        self.host = host
        self.port = port
        self.server_socket = None
        self.running = False
        
    def start(self):
        """Start UDP server"""
        try:
            # Create UDP socket
            self.server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
            self.server_socket.bind((self.host, self.port))
            self.running = True
            
            print(f"UDP Server started on {self.host}:{self.port}")
            print("Waiting for messages...")
            
            while self.running:
                try:
                    # Receive data and client address
                    data, client_address = self.server_socket.recvfrom(1024)
                    message = data.decode('utf-8').strip()
                    
                    print(f"Received from {client_address}: {message}")
                    
                    # Send response back
                    response = f"UDP Server received: {message}"
                    self.server_socket.sendto(response.encode('utf-8'), client_address)
                    
                except KeyboardInterrupt:
                    print("\nUDP Server shutting down...")
                    self.stop()
                    break
                    
        except Exception as e:
            print(f"UDP Server error: {e}")
            self.stop()
    
    def stop(self):
        self.running = False
        if self.server_socket:
            self.server_socket.close()

# Simple Client to Test the Server
def simple_client_test():
    """Simple client to test the server"""
    import socket
    import time
    
    # TCP Client
    def tcp_client():
        client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        try:
            client_socket.connect(('localhost', 5000))
            messages = ["Hello Server!", "How are you?", "Test Message"]
            
            for msg in messages:
                client_socket.sendall(msg.encode('utf-8'))
                response = client_socket.recv(1024)
                print(f"Server response: {response.decode('utf-8')}")
                time.sleep(1)
                
        finally:
            client_socket.close()
    
    # UDP Client
    def udp_client():
        client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        messages = ["UDP Message 1", "UDP Message 2"]
        
        for msg in messages:
            client_socket.sendto(msg.encode('utf-8'), ('localhost', 5001))
            response, _ = client_socket.recvfrom(1024)
            print(f"UDP Server response: {response.decode('utf-8')}")
            time.sleep(1)
        
        client_socket.close()
    
    # Run tests
    print("Testing TCP Client...")
    tcp_client()
    
    print("\nTesting UDP Client...")
    udp_client()

if __name__ == "__main__":
    # Start TCP server in background thread
    tcp_server = MessageServer(port=5000)
    tcp_thread = threading.Thread(target=tcp_server.start)
    tcp_thread.daemon = True
    tcp_thread.start()
    
    # Start UDP server in background thread
    udp_server = UDPMessageServer(port=5001)
    udp_thread = threading.Thread(target=udp_server.start)
    udp_thread.daemon = True
    udp_thread.start()
    
    # Wait a moment for servers to start
    import time
    time.sleep(2)
    
    # Run client test
    simple_client_test()
    
    # Keep running
    try:
        while True:
            time.sleep(1)
    except KeyboardInterrupt:
        tcp_server.stop()
        udp_server.stop()
        print("\nAll servers stopped")