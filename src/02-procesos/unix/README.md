## Memory Layout Example Explanation

This example demonstrates the memory layout of a C program, showing how variables are stored in different memory segments.

### Key Components

1. **Global Variables**

   ```c
   int x;
   int y = 15;
   ```

   - `x` is an uninitialized global variable (stored in the BSS segment).
   - `y` is an initialized global variable (stored in the Data segment).

2. **Dynamic Memory Allocation**

   ```c
   int *values;
   values = (int *)malloc(sizeof(int) * 5);
   ```

   - Allocates memory for an array of 5 integers on the Heap.

3. **Stack Variables**
   ```c
   int i;
   for (i = 0; i < 5; i++)
     values[i] = i;
   ```
   - `i` is a local variable (stored on the Stack).
   - The loop initializes the dynamically allocated array.

### Compilation and Execution

```bash
# Compile the example
gcc src/02-procesos/unix/memory_layout_example.c -o memory_layout_example

# Run the program
./memory_layout_example
```

### Explanation

- **BSS Segment:** Stores uninitialized global/static variables (`x`).
- **Data Segment:** Stores initialized global/static variables (`y`).
- **Heap:** Stores dynamically allocated memory (`values` array).
- **Stack:** Stores local variables and function call information (`i`, function parameters).

This example helps visualize how a C program's memory is organized at runtime.

---

## Fork Example Explanation

This example demonstrates process creation and management using fork() in C:

### Key Components

1. **Process Creation**

   ```c
   pid_t pid = fork();
   ```

   Creates a new child process that is an exact copy of the parent process.

2. **Process Identification**

   ```c
   printf("Child process %d (PID: %d, Parent PID: %d) starting...\n",
          i + 1, getpid(), getppid());
   ```

   Shows how to identify processes using:

   - `getpid()`: Get current process ID
   - `getppid()`: Get parent process ID

3. **Process Synchronization**
   ```c
   while ((pid = wait(&status)) > 0) {
       printf("Child process (PID: %d) finished with status %d\n",
              pid, WEXITSTATUS(status));
   }
   ```
   Parent process waits for all child processes to complete using `wait()`.

### Compilation and Execution

```bash
# Compile the example
gcc src/02-procesos/fork_example.c -o fork_example

# Run the program
./fork_example
```

### Expected Output

```
Parent process (PID: xxxx) starting...
Child process 1 (PID: yyyy, Parent PID: xxxx) starting...
Child process 2 (PID: zzzz, Parent PID: xxxx) starting...
Child process 3 (PID: wwww, Parent PID: xxxx) starting...
Child process (PID: yyyy) finished with status 0
Child process (PID: zzzz) finished with status 0
Child process (PID: wwww) finished with status 0
```

Note: The actual PIDs will be different on each run.

---

## Fork & Exec Example Explanation

This example demonstrates process creation and command execution using fork() and exec() in C:

### Key Components

1. **Process Creation**

   ```c
   pid_t pid = fork();
   ```

   Creates a new child process that is an exact copy of the parent process.

2. **Command Execution**

   ```c
   execlp("/bin/ls", "ls", NULL);
   ```

   Child process executes the 'ls' command:

   - `execlp`: Executes a file using PATH environment variable
   - First argument: Path to executable
   - Second argument: Program name
   - NULL: Ends argument list

3. **Parent Waiting**
   ```c
   wait(NULL);
   printf("Child Complete \n");
   ```
   Parent process waits for child to complete before continuing.

### Compilation and Execution

```bash
# Compile the example
gcc src/02-procesos/fork2_example.c -o fork2_example

# Run the program
./fork2_example
```

### Expected Output

```
[Directory listing from ls command]
Child Complete
```

Note: The actual directory listing will depend on your current directory contents.
