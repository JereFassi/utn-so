import socket

def start_server(host='127.0.0.1', port=65432):
  """Starts the server to listen for connections."""
  with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((host, port))
    s.listen()
    print(f"Server listening on {host}:{port}")
    conn, addr = s.accept()
    with conn:
      print(f"Connected by {addr}")
      while True:
        data = conn.recv(1024) # Receive data from client (buffer size 1024 bytes)
        if not data:
          break # Connection closed by client
        print(f"Received from client: {data.decode()}")
        # Send response back to client
        response = f"Server received: {data.decode()}"
        conn.sendall(response.encode())
        print("Connection closed.")

if __name__ == "__main__":
  start_server()