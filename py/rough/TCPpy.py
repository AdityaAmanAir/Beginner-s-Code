import socket
import threading

class MessageServer:
    def __init__(self, host='localhost', port=5000):
        self.host = host
        self.port = port
        self.server_socket = None
        self.running = False
        
    def start(self):
        """Start the TCP server to receive messages"""
        try:
            # Create TCP socket
            self.server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            self.server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
            
            # Bind to host and port
            self.server_socket.bind((self.host, self.port))
            
            # Listen for incoming connections (max 5 queued connections)
            self.server_socket.listen(5)
            self.running = True
            
            print(f"Server started on {self.host}:{self.port}")
            print("Waiting for client connections...")
            
            while self.running:
                try:
                    # Accept client connection
                    client_socket, client_address = self.server_socket.accept()
                    print(f"Connection from {client_address}")
                    
                    # Handle client in a new thread
                    client_thread = threading.Thread(
                        target=self.handle_client,
                        args=(client_socket, client_address)
                    )
                    client_thread.daemon = True
                    client_thread.start()
                    
                except KeyboardInterrupt:
                    print("\nServer shutting down...")
                    self.stop()
                    break
                    
        except Exception as e:
            print(f"Server error: {e}")
            self.stop()
    
    def handle_client(self, client_socket, client_address):
        """Handle communication with a single client"""
        try:
            with client_socket:
                while True:
                    # Receive data from client (max 1024 bytes)
                    data = client_socket.recv(1024)
                    if not data:
                        print(f"Client {client_address} disconnected")
                        break
                    
                    # Decode and process message
                    message = data.decode('utf-8').strip()
                    print(f"Received from {client_address}: {message}")
                    
                    # Send acknowledgment back to client
                    response = f"Server received: {message}"
                    client_socket.sendall(response.encode('utf-8'))
                    
        except ConnectionError:
            print(f"Connection with {client_address} lost")
        except Exception as e:
            print(f"Error handling client {client_address}: {e}")
    
    def stop(self):
        """Stop the server"""
        self.running = False
        if self.server_socket:
            self.server_socket.close()
            print("Server socket closed")

if __name__ == "__main__":
    # Create and start server
    server = MessageServer(host='localhost', port=5000)
    
    # You can also run in a separate thread
    server_thread = threading.Thread(target=server.start)
    server_thread.daemon = True
    server_thread.start()
    
    # Keep main thread alive
    try:
        while True:
            pass
    except KeyboardInterrupt:
        server.stop()
        print("\nServer stopped by user")