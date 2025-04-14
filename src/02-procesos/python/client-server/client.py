import socket

def start_client(host='127.0.0.1', port=65432, message="Hello, Server!"):
  """Starts the client to connect to the server and send a message."""
  with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    try:
      s.connect((host, port))
      print(f"Connected to server {host}:{port}")
      # Send message to server
      print(f"Sending: {message}")
      s.sendall(message.encode())
      # Receive response from server
      data = s.recv(1024) # Receive data from server (buffer size 1024 bytes)
      print(f"Received from server: {data.decode()}")
    except ConnectionRefusedError:
      print(f"Error: Connection refused. Is the server running on {host}:{port}?")
    except Exception as e:
      print(f"An error occurred: {e}")
    finally:
      print("Closing connection.")

if __name__ == "__main__":
  # You can change the message here or get it from user input
  message_to_send = "Hello from the client!"
  start_client(message=message_to_send)