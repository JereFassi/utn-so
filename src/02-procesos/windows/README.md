## Windows Process Creation Example

### Windows Setup Instructions

1. **Install GCC Compiler**

   - Install MSYS2: https://www.msys2.org/
   - Follow MinGW-w64 setup: https://www.mingw-w64.org/getting-started/msys2/
   - Or follow VS Code's guide: https://code.visualstudio.com/docs/cpp/config-mingw

2. **Setup Environment**

   ```powershell
   # Add MinGW to PATH if not done during installation
   # Usually located at: C:\msys64\mingw64\bin
   ```

3. **Paint Installation Path - Windows 10**
   ```
   "C:\\Windows\\system32\\mspaint.exe"
   ```
4. **Find Paint Installation Path - Windows 11**

   ```powershell
   # Run in PowerShell as administrator
   Get-AppxPackage -allusers Microsoft.Paint | Select-Object -Property Name, InstallLocation
   ```

   Example output:

   ```
   Name              : Microsoft.Paint_11.2502.161.0_x64__8wekyb3d8bbwe
   InstallLocation   : C:\Program Files\WindowsApps\Microsoft.Paint_11.2502.161.0_x64__8wekyb3d8bbwe
   ```

5. **Update Source Code**

   - Replace the Paint path in your code with the InstallLocation from above
   - Add `\PaintApp\mspaint.exe` to the path

6. **Compile and Run**

   ```bash
   # Compile
   gcc create_process_example.c -o create_process_example.exe

   # Run
   ./create_process_example.exe
   ```

Note: The Paint installation path may vary depending on your Windows version and installation.

## Process Creation Example

This example demonstrates how to create child processes in Windows using the Windows API:

### Key Components

1. **Process Information Structures**

   ```c
   STARTUPINFO si;
   PROCESS_INFORMATION pi;
   ZeroMemory(&si, sizeof(si));
   si.cb = sizeof(si);
   ```

   Initialize required structures:

   - `STARTUPINFO`: Contains window settings for new process
   - `PROCESS_INFORMATION`: Receives identification information
   - `ZeroMemory`: Clears memory to avoid undefined behavior

2. **Process Creation**

   ```c
   CreateProcess(
     NULL,    // No module name (use command line)
     "path/to/mspaint.exe",  // Command line
     NULL,    // Process handle not inheritable
     NULL,    // Thread handle not inheritable
     FALSE,   // Set handle inheritance to FALSE
     0,       // No creation flags
     NULL,    // Use parent's environment block
     NULL,    // Use parent's starting directory
     &si,     // Pointer to STARTUPINFO structure
     &pi      // Pointer to PROCESS_INFORMATION structure
   );
   ```

   Creates a new process and its primary thread.

3. **Process Synchronization**
   ```c
   WaitForSingleObject(pi.hProcess, INFINITE);
   printf("Child Complete");
   ```
   Parent process waits for child to complete.

### Compilation and Execution

```bash
# Compile the basic example
gcc create_process_example.c -o create_process_example.exe

# Run the program
./create_process_example.exe
```

### Extended Version with Arguments

The second version (`create_process2_example.c`) adds:

- Command line argument support
- Default image path handling
- Better error messages

```bash
# Compile the extended example
gcc create_process2_example.c -o create_process2_example.exe

# Run with default image
./create_process2_example.exe default

# Run with specific image
./create_process2_example.exe "C:\path\to\image.jpg"
```

### Notes

- Requires Windows OS
- Uses Windows API (`windows.h`)
- Microsoft Paint must be installed
- Remember to clean up handles after use
- Check process permissions if Paint fails to open
