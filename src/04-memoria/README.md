## Shared Memory Example Explanation

This example demonstrates shared memory management in C using POSIX shared memory objects:

### Key Components

1. **Shared Memory Creation**
   ```c
   shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
   if (ftruncate(shm_fd, SHM_SIZE) == -1) {
       perror("ftruncate");
       exit(1);
   }
   ```
   Creates and configures a shared memory segment with:
   - `shm_open()`: Create/open a shared memory object
   - `ftruncate()`: Set the size of the shared memory segment

2. **Memory Mapping**
   ```c
   shm_ptr = mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
   ```
   Maps the shared memory segment into the process address space with:
   - `PROT_READ | PROT_WRITE`: Read and write permissions
   - `MAP_SHARED`: Changes are visible to other processes

3. **Memory Cleanup**
   ```c
   munmap(shm_ptr, SHM_SIZE);
   shm_unlink(SHM_NAME);
   ```
   Proper cleanup of shared memory resources:
   - `munmap()`: Unmap memory segment
   - `shm_unlink()`: Remove shared memory object

### Compilation and Execution
```bash
# Compile the example (note the -lrt flag for POSIX real-time extensions)
gcc src/04-memoria/shared_memory.c -o shared_memory -lrt

# Run the program
./shared_memory
```

### Expected Output
```
Written to shared memory: Hello from shared memory!
```

Note: This example requires a POSIX-compliant system with shared memory support.