## Input Example Explanation

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