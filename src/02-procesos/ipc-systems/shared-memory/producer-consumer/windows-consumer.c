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

  // Open file mapping
  hMapFile = OpenFileMapping(
    FILE_MAP_ALL_ACCESS,    // Read/write access
    FALSE,                  // Do not inherit the name
    SHARED_MEM_NAME         // Name of mapping object
  );

  if (hMapFile == NULL) {
    printf("Could not open file mapping object (%d).\n", GetLastError());
    return 1;
  }

  // Map shared memory
  shared_mem = (shared_memory_t*)MapViewOfFile(
    hMapFile,              // Handle to mapping object
    FILE_MAP_ALL_ACCESS,   // Read/write permission
    0,                     // Offset high
    0,                     // Offset low
    sizeof(shared_memory_t)
  );

  if (shared_mem == NULL) {
    printf("Could not map view of file (%d).\n", GetLastError());
    CloseHandle(hMapFile);
    return 1;
  }

  printf("Consumer ready. Waiting for messages...\n");

  while (1) {
    if (shared_mem->count > 0) {
      printf("Consumed: %s", shared_mem->buffer);
      shared_mem->count = 0;
      Sleep(1000);  // Windows sleep function (milliseconds)
    }
  }

  // Cleanup
  UnmapViewOfFile(shared_mem);
  CloseHandle(hMapFile);

  return 0;
}