## Producer-Consumer Example Explanation

This example demonstrates inter-process communication using shared memory in both Windows and UNIX systems:

### Key Components

1. **Shared Memory Structure**
   ```c
   typedef struct {
     int count;          // Number of items in buffer
     char buffer[BUFFER_SIZE];  // Shared buffer
   } shared_memory_t;
   ```
   Defines the structure shared between processes:
   - `count`: Controls synchronization
   - `buffer`: Stores the shared data

2. **Windows Implementation**
   ```c
   // Create shared memory
   hMapFile = CreateFileMapping(
     INVALID_HANDLE_VALUE,    // Use paging file
     NULL,                    // Default security
     PAGE_READWRITE,         // Read/write access
     0,                      // Maximum object size
     sizeof(shared_memory_t), // Size of shared memory
     SHARED_MEM_NAME);       // Name of mapping object
   ```
   Uses Windows API for shared memory:
   - `CreateFileMapping`: Creates shared memory segment
   - `MapViewOfFile`: Maps memory into process space
   - `UnmapViewOfFile`: Releases mapped memory

3. **UNIX Implementation**
   ```c
   // Create shared memory
   shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
   ftruncate(shm_fd, sizeof(shared_memory_t));
   shared_mem = mmap(NULL, sizeof(shared_memory_t), 
                    PROT_READ | PROT_WRITE, MAP_SHARED, 
                    shm_fd, 0);
   ```
   Uses POSIX shared memory:
   - `shm_open`: Creates shared memory object
   - `mmap`: Maps memory into process space
   - `munmap`: Unmaps shared memory

### Compilation and Execution

For Windows:
```bash
# Compile producer and consumer
gcc windows-producer.c -o windows-producer.exe
gcc windows-consumer.c -o windows-consumer.exe

# Run in separate Command Prompt windows
./windows-consumer.exe
./windows-producer.exe
```

For UNIX:
```bash
# Compile producer and consumer
gcc unix-producer.c -o unix-producer -lrt
gcc unix-consumer.c -o unix-consumer -lrt

# Run in separate terminal windows
./unix-consumer
./unix-producer
```

### Example Usage
```
# In consumer window:
Consumer ready. Waiting for messages...

# In producer window:
Producer ready. Enter messages (Ctrl+Z/D to exit):
Hello World!
Produced: Hello World!
```

### Notes
- Windows version uses Windows API (`CreateFileMapping`, `MapViewOfFile`)
- UNIX version uses POSIX shared memory (`shm_open`, `mmap`)
- Producer writes messages to shared buffer
- Consumer continuously checks for and displays new messages
- Basic synchronization using count variable