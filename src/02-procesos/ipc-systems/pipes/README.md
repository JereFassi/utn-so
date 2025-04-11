## Pipe Communication Example

This example demonstrates inter-process communication using pipes in UNIX systems:

### Key Components

1. **Pipe Creation**
   ```c
   int fd[2];
   if (pipe(fd) == -1) {
       fprintf(stderr,"Pipe failed");
       return 1;
   }
   ```
   Creates a pipe with two file descriptors:
   - `fd[0]`: Read end of pipe
   - `fd[1]`: Write end of pipe

2. **Process Creation**
   ```c
   pid_t pid = fork();
   ```
   Creates a child process that inherits pipe file descriptors.

3. **Parent Process (Writer)**
   ```c
   if (pid > 0) {
       close(fd[READ_END]);
       write(fd[WRITE_END], write_msg, strlen(write_msg) + 1);
       close(fd[WRITE_END]);
   }
   ```
   - Closes unused read end
   - Writes message to pipe
   - Closes write end when done

4. **Child Process (Reader)**
   ```c
   else {
       close(fd[WRITE_END]);
       read(fd[READ_END], read_msg, BUFFER_SIZE);
       printf("read %s", read_msg);
       close(fd[READ_END]);
   }
   ```
   - Closes unused write end
   - Reads message from pipe
   - Displays received message

### Compilation and Execution
```bash
# Compile the example
gcc pipe_example.c -o pipe_example

# Run the program
./pipe_example
```

### Expected Output
```
read Greetings!
```

### Notes
- Only works on UNIX-like systems (Linux, macOS)
- Demonstrates unidirectional communication
- Parent sleeps to ensure proper synchronization
- Proper cleanup by closing unused pipe ends
- Uses system calls: `pipe()`, `fork()`, `read()`, `write()`

### Important Concepts
1. Pipes are unidirectional
2. Data flows from write end to read end
3. Unused ends should be closed
4. Pipe provides synchronized communication
5. Pipe exists only while processes are running