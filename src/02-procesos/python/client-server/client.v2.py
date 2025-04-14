import socket
import sys

def start_client(host='127.0.0.1', port=65432):
  """Starts the client to connect to the server and send messages interactively."""
  with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    try:
      # Connect to the server using the specified host and port
      s.connect((host, port))
      print(f"Connected to server {host}:{port}")
      print("Enter messages to send (type 'quit' or 'exit' to stop):")

      while True:
        try:
          # Get message from keyboard input
          message = input("> ")
          if message.lower() in ['quit', 'exit']:
            break # Exit loop if user types quit or exit

          # Send message to server
          print(f"Sending: {message}")
          s.sendall(message.encode())

          # Receive response from server
          data = s.recv(1024) # Receive data from server (buffer size 1024 bytes)
          if not data:
            print("Server closed the connection.")
            break
          
          # print(f"Received from server: {data.decode()}")

        except EOFError: # Handle Ctrl+D or end of input stream
          print("\nInput stream closed.")
          break
        except KeyboardInterrupt: # Handle Ctrl+C
          print("\nInterrupted by user.")
          break

    except ConnectionRefusedError:
      print(f"Error: Connection refused. Is the server running on {host}:{port}?")
    except Exception as e:
      print(f"An error occurred: {e}")
    finally:
      print("Closing connection.")

if __name__ == "__main__":
    start_client()