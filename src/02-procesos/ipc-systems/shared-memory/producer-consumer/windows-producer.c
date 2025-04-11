#include <stdio.h>
#include <windows.h>

#define BUFFER_SIZE 1024
#define SHARED_MEM_NAME "Local\\SharedMemory"

typedef struct {
  int count;
  char buffer[BUFFER_SIZE];
} shared_memory_t;

int main() 
{
  HANDLE hMapFile;
  shared_memory_t *shared_mem;
  char input[BUFFER_SIZE];

  // Create file mapping
  hMapFile = CreateFileMapping(
    INVALID_HANDLE_VALUE,     // Use paging file
    NULL,                     // Default security
    PAGE_READWRITE,           // Read/write access
    0,                        // Maximum object size (high-order DWORD)
    sizeof(shared_memory_t),  // Maximum object size (low-order DWORD)
    SHARED_MEM_NAME           // Name of mapping object
  );        

  if (hMapFile == NULL) {
    printf("Could not create file mapping object (%d).\n", GetLastError());
    return 1;
  }

  // Map shared memory
  shared_mem = (shared_memory_t*)MapViewOfFile(
    hMapFile,               // Handle to mapping object
    FILE_MAP_ALL_ACCESS,    // Read/write permission
    0,                      // Offset high
    0,                      // Offset low
    sizeof(shared_memory_t) // Size of the mapping object
  );

  if (shared_mem == NULL) {
    printf("Could not map view of file (%d).\n", GetLastError());
    CloseHandle(hMapFile);
    return 1;
  }

  // Initialize shared memory
  shared_mem->count = 0;

  printf("Producer ready. Enter messages (Ctrl+Z to exit):\n");

  while (fgets(input, BUFFER_SIZE, stdin) != NULL) {
    // Wait if buffer is full
    while (shared_mem->count > 0) {
      printf("Buffer full, waiting...\n");
      Sleep(1000);  // Windows sleep function (milliseconds)
    }

    // Copy input to shared memory
    strncpy(shared_mem->buffer, input, BUFFER_SIZE);
    shared_mem->count++;

    printf("Produced: %s", input);
  }

  // Cleanup
  UnmapViewOfFile(shared_mem);
  CloseHandle(hMapFile);

  return 0;
}