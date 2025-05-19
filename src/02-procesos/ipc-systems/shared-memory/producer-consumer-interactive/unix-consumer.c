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

  // Open shared memory object
  shm_fd = shm_open(SHM_NAME, O_RDWR, 0666);
  if (shm_fd == -1) {
    perror("shm_open");
    exit(1);
  }

  // Map shared memory
  shared_mem = mmap(NULL, sizeof(shared_memory_t), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
  
  if (shared_mem == MAP_FAILED) {
    perror("mmap");
    exit(1);
  }

  printf("Consumer ready. Waiting for messages...\n");

  while (1) {
    // Check if there's data to consume
    if (shared_mem->count > 0) {
      printf("Consumed: %s", shared_mem->buffer);
      shared_mem->count = 0;  // Mark as consumed
    }
    sleep(1);  // Wait before checking again
  }

  // Cleanup
  munmap(shared_mem, sizeof(shared_memory_t));
  close(shm_fd);

  return 0;
}