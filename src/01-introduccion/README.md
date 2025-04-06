## Read Input Example Explanation

This example demonstrates basic input/output operations in C:

### Key Components

1. **Input Buffer Declaration**
   ```c
   char input[100];
   ```
   Creates a fixed-size buffer to store user input (100 characters maximum).

2. **Reading User Input**
   ```c
   fgets(input, sizeof(input), stdin);
   ```
   Safely reads a line of text from standard input, preventing buffer overflows.

3. **Displaying Output**
   ```c
   printf("You entered: %s", input);
   ```
   Prints the user's input back to the console.

### Compilation and Execution
```bash
# Compile the example
gcc src/01-introduccion/read_input_example.c -o read_input_example

# Run the program
./read_input_example
```

---

## Read File Example Explanation

This example demonstrates file handling operations in C using the standard I/O library:

### Key Components

1. **Buffer Declaration**
   ```c
   #define BUFFER_SIZE 1024
   char buffer[BUFFER_SIZE];
   ```
   Creates a fixed-size buffer to store file contents during reading.

2. **File Opening**
   ```c
   FILE *file;
   file = fopen("src/01-introduccion/tuc.txt", "r");
   ```
   Opens the file in read mode and checks for errors:
   - Returns NULL if file cannot be opened
   - "r" flag indicates read-only mode

3. **File Reading**
   ```c
   while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
       printf("%s", buffer);
   }
   ```
   Reads the file line by line until EOF is reached:
   - `fgets`: Reads up to BUFFER_SIZE-1 characters or until newline
   - Automatically handles line endings
   - NULL return indicates EOF or error

4. **File Closing**
   ```c
   if (fclose(file) != 0) {
       perror("Error closing file");
       return 1;
   }
   ```
   Properly closes the file and handles potential errors.

### Compilation and Execution
```bash
# Compile the example
gcc src/01-introduccion/read_file_example.c -o read_file_example

# Run the program
./read_file_example
```

### Key Differences between fgets and read
- `fgets` is a buffered C library function, `read` is a system call
- `fgets` is part of standard C, `read` is POSIX-specific
- `fgets` works with FILE pointers, `read` uses file descriptors
- `fgets` reads until newline, `read` reads exact byte count