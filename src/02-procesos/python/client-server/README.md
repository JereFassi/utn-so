# Python Socket Communication Examples

This project demonstrates client-server communication using Python's socket programming. It includes both basic and improved implementations showing how to establish TCP connections and exchange messages between clients and servers.

## Project Structure

### Basic Implementation

- **`server.py`**: Basic TCP server that:

  - Listens on localhost (127.0.0.1:65432)
  - Accepts one client connection
  - Receives a single message
  - Responds with an acknowledgment
  - Closes the connection

- **`client.py`**: Basic TCP client that:
  - Connects to the server
  - Sends a predefined message
  - Receives and displays the server's response
  - Closes the connection

### Improved Implementation (v2)

- **`server.v2.py`**: Enhanced server with:

  - Socket address reuse (`SO_REUSEADDR`)
  - Continuous message handling
  - Graceful connection termination on 'bye'
  - Better error handling and logging

- **`client.v2.py`**: Interactive client featuring:
  - User input for messages
  - Continuous communication
  - Multiple exit commands ('quit', 'exit', 'bye')
  - Improved error handling
  - Signal handling (Ctrl+C, Ctrl+D)

## Requirements

- Python 3.6 or higher
- No external dependencies required (uses standard library only)

## Running the Examples

### Basic Version

1. Start the server:

   ```bash
   python server.py
   ```

2. In a new terminal, run the client:
   ```bash
   python client.py
   ```

### Improved Version (v2)

1. Start the improved server:

   ```bash
   python server.v2.py
   ```

2. In a new terminal, start the interactive client:

   ```bash
   python client.v2.py
   ```

3. **Interactive Commands:**
   - Type any message and press Enter to send
   - Use these commands to exit:
     - `bye` - graceful shutdown (notifies server)
     - `quit` or `exit` - local client shutdown
     - `Ctrl+C` - force quit
   - `Ctrl+D` - close input stream (Unix-like systems)

## Communication Protocol

- **Connection**: TCP on localhost (127.0.0.1:65432)
- **Message Format**: UTF-8 encoded strings
- **Buffer Size**: 1024 bytes
- **Termination Signal**: 'bye' message or connection close

## Error Handling

- Connection refused
- Unexpected disconnections
- Input/Output errors
- Keyboard interrupts
- EOF conditions

## Notes

- The v2 implementation is recommended for learning and testing
- Both server versions handle one client at a time
- The server automatically frees the socket address for quick restart
- Messages are echoed back with "Server received: " prefix

## Future Improvements

- Multi-client support using threading
- Custom message protocols
- Data encryption
- Connection timeout handling
- Message size validation
