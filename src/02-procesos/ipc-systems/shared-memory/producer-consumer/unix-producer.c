#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>

#define SHM_NAME "/shm_example"
#define BUFFER_SIZE 1024

typedef struct {
  int count;          // Number of items in buffer
  char buffer[BUFFER_SIZE];  // Shared buffer
} shared_memory_t;

int main() 
{
  int shm_fd;
  shared_memory_t *shared_mem;
  char input[BUFFER_SIZE];

  // Create shared memory object
  shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
  if (shm_fd == -1) {
    perror("shm_open");
    exit(1);
  }

  // Configure size
  ftruncate(shm_fd, sizeof(shared_memory_t));

  // Map shared memory
  shared_mem = mmap(NULL, sizeof(shared_memory_t), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
  
  if (shared_mem == MAP_FAILED) {
    perror("mmap");
    exit(1);
  }

  // Initialize shared memory
  shared_mem->count = 0;

  printf("Producer ready. Enter messages (Ctrl+D to exit):\n");

  while (fgets(input, BUFFER_SIZE, stdin) != NULL) {
    // Wait if buffer is full
    while (shared_mem->count > 0) {
      printf("Buffer full, waiting...\n");
      sleep(1);
    }
  
    // Copy input to shared memory
    strncpy(shared_mem->buffer, input, BUFFER_SIZE);
    shared_mem->count++;

    printf("Produced: %s", input);
  }

  // Cleanup
  munmap(shared_mem, sizeof(shared_memory_t));
  close(shm_fd);
  shm_unlink(SHM_NAME);

  return 0;
}