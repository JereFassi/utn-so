#include <omp.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
  /* sequential code */
  printf("I am a sequential region. INIT. \n");
/* parallel region */
#pragma omp parallel
  {
    printf("I am a parallel region. \n");
  }
  /* sequential code */
  printf("I am a sequential region. DONE. \n");
  return 0;
}

/*
  Compilation:
  gcc -fopenmp -o open_MP_example open_MP_example.c
  Execution:
  ./open_MP_example
  Output:
  I am a sequential region. INIT.
  I am a parallel region.
  I am a parallel region.
  I am a parallel region.
  I am a parallel region.
  I am a sequential region. DONE.
*/