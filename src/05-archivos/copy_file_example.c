#include <sys/types.h> /* include necessary header files */
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h> /* for printf (optional, for better error messages) */

#define BUF_SIZE 4096    /* use a buffer size of 4096 bytes */
#define OUTPUT_MODE 0700 /* protection bits for output file */

int main(int argc, char *argv[])
{
  int in_fd, out_fd, rd_count, wt_count;
  char buffer[BUF_SIZE];

  /* Check for correct number of arguments */
  if (argc != 3)
  {
    printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
    exit(1); /* syntax error if argc is not 3 */
  }

  /* Open the input file (source) */
  in_fd = open(argv[1], O_RDONLY);
  if (in_fd < 0)
  {
    printf("Error: cannot open source file '%s'\n", argv[1]);
    exit(2); /* if it cannot be opened, exit */
  }

  /* Create the output file (destination) */
  out_fd = creat(argv[2], OUTPUT_MODE);
  if (out_fd < 0)
  {
    printf("Error: cannot create destination file '%s'\n", argv[2]);
    close(in_fd);
    exit(3); /* if it cannot be created, exit */
  }

  /* Copy loop: read from source and write to destination */
  while (1)
  {
    /* Read up to BUF_SIZE bytes from the input file */
    rd_count = read(in_fd, buffer, BUF_SIZE);

    if (rd_count < 0)
    {
      /* Error occurred during read */
      printf("Error: reading from source file\n");
      close(in_fd);
      close(out_fd);
      exit(5);
    }

    if (rd_count == 0)
    {
      /* End of file reached */
      break;
    }

    /* Write the bytes read to the output file */
    wt_count = write(out_fd, buffer, rd_count);

    if (wt_count < 0)
    {
      /* Error occurred during write */
      printf("Error: writing to destination file\n");
      close(in_fd);
      close(out_fd);
      exit(4);
    }

    /* If not all bytes were written, handle error */
    if (wt_count != rd_count)
    {
      printf("Error: incomplete write to destination file\n");
      close(in_fd);
      close(out_fd);
      exit(4);
    }
  }

  /* Close the files */
  close(in_fd);
  close(out_fd);

  printf("File copied successfully.\n");
  exit(0);
}