import socket

def start_server(host='127.0.0.1', port=65432):
  """Starts the server to listen for connections."""
  # Use SO_REUSEADDR to allow reusing the address quickly after server stops
  with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    s.bind((host, port))
    s.listen()
    print(f"Server listening on {host}:{port}")
    conn, addr = s.accept()
    with conn:
      print(f"Connected by {addr}")
      while True:
        data = conn.recv(1024) # Receive data from client (buffer size 1024 bytes)
        if not data:
          print("Client disconnected unexpectedly.")
          break # Connection closed by client

        message = data.decode()
        print(f"Received from client: {message}")

        # Check if the client sent 'bye'
        if message.lower() == 'bye':
          print("Client sent 'bye'. Closing connection.")
          conn.sendall("Server acknowledging bye. Goodbye!".encode())
          break # Exit the loop for this client

        # Send response back to client
        response = f"Server received: {message}"
        conn.sendall(response.encode())

      print(f"Connection with {addr} closed.") # Moved outside the loop

if __name__ == "__main__":
  start_server()