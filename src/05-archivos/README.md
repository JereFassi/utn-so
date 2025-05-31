> 🇪🇸 [Leer en español](README.es.md)

# File Copy Program in C

This program demonstrates how to copy the contents of one file to another using system calls in C. It includes error handling for common issues such as file access and read/write errors.

---

## 📋 How It Works

1. **Command-Line Arguments**  
   The program expects two arguments:

   - `source_file`: The file to be copied.
   - `destination_file`: The file where the contents will be copied.

   Example usage:

   ```bash
   ./copy_file_example source.txt destination.txt
   ```

2. **Opening Files**

   - The source file is opened in read-only mode using `open()`.
   - The destination file is created (or overwritten if it exists) using `creat()` with permissions `0700` (read, write, and execute for the owner).

3. **Copying Data**

   - A buffer of size `4096` bytes is used to read chunks of data from the source file and write them to the destination file.
   - The program uses a loop to read and write until the end of the source file is reached.

4. **Error Handling**

   - The program checks for errors at every step:
     - If the source file cannot be opened, it exits with an error message.
     - If the destination file cannot be created, it exits with an error message.
     - If a read or write operation fails, it exits with an error message.

5. **Closing Files**

   - Both the source and destination files are closed after the copying process is complete.

6. **Success Message**
   - If the file is copied successfully, a success message is printed.

---

## 🛠️ Code Breakdown

### Key Components

1. **Buffer and Permissions**

   ```c
   #define BUF_SIZE 4096    /* Buffer size for copying */
   #define OUTPUT_MODE 0700 /* Permissions for the destination file */
   ```

2. **Opening Files**

   ```c
   in_fd = open(argv[1], O_RDONLY);
   if (in_fd < 0) {
       printf("Error: cannot open source file '%s'\n", argv[1]);
       exit(2);
   }

   out_fd = creat(argv[2], OUTPUT_MODE);
   if (out_fd < 0) {
       printf("Error: cannot create destination file '%s'\n", argv[2]);
       close(in_fd);
       exit(3);
   }
   ```

3. **Copy Loop**

   ```c
   while (1) {
       rd_count = read(in_fd, buffer, BUF_SIZE);
       if (rd_count < 0) {
           printf("Error: reading from source file\n");
           close(in_fd);
           close(out_fd);
           exit(5);
       }
       if (rd_count == 0) {
           break; /* End of file reached */
       }
       wt_count = write(out_fd, buffer, rd_count);
       if (wt_count < 0 || wt_count != rd_count) {
           printf("Error: writing to destination file\n");
           close(in_fd);
           close(out_fd);
           exit(4);
       }
   }
   ```

4. **Closing Files**
   ```c
   close(in_fd);
   close(out_fd);
   printf("File copied successfully.\n");
   ```

---

## 🚀 How to Compile and Run

1. **Compile the Program**

   ```bash
   gcc copy_file_example.c -o copy_file_example
   ```

2. **Run the Program**
   ```bash
   ./copy_file_example source.txt destination.txt
   ```

---

## 📝 Example Output

### Successful Copy

```bash
$ ./copy_file_example source.txt destination.txt
File copied successfully.
```

### Error: Source File Not Found

```bash
$ ./copy_file_example nonexistent.txt destination.txt
Error: cannot open source file 'nonexistent.txt'
```

### Error: Cannot Create Destination File

```bash
$ ./copy_file_example source.txt /protected/destination.txt
Error: cannot create destination file '/protected/destination.txt'
```

---

## 🔍 Notes

- The program overwrites the destination file if it already exists.
- The buffer size (`BUF_SIZE`) can be adjusted for performance optimization.
- Ensure you have the necessary permissions to read the source file and write to the destination file.
