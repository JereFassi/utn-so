/* POSIX Shared Memory Example*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define SHM_NAME "/my_shm"
#define SHM_SIZE 1024

int main() 
{
  int shm_fd;
  void *shm_ptr;

  // Create shared memory object
  shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
  if (shm_fd == -1) {
    perror("shm_open");
    exit(1);
  }

  // Configure size
  if (ftruncate(shm_fd, SHM_SIZE) == -1) {
    perror("ftruncate");
    exit(1);
  }

  // Map shared memory
  shm_ptr = mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
  if (shm_ptr == MAP_FAILED) {
    perror("mmap");
    exit(1);
  }

  // Write to shared memory
  sprintf(shm_ptr, "Hello from shared memory!");
  printf("Written to shared memory: %s\n", (char*)shm_ptr);

  // Cleanup
  if (munmap(shm_ptr, SHM_SIZE) == -1) {
    perror("munmap");
    exit(1);
  }

  if (shm_unlink(SHM_NAME) == -1) {
    perror("shm_unlink");
    exit(1);
  }

  return 0;
}