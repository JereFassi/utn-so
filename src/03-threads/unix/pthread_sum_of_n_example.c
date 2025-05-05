#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int sum; /* this data is shared by the thread(s) */

void *runner(void *param); /* threads call this function */

int main(int argc, char *argv[])
{
  pthread_t tid;       /* the thread identifier */
  pthread_attr_t attr; /* set of thread attributes */
  /* set the default attributes of the thread */
  pthread_attr_init(&attr);
  /* create the thread */
  pthread_create(&tid, &attr, runner, argv[1]);
  /* wait for the thread to exit */
  pthread_join(tid, NULL);
  printf("sum = %d\n", sum);
}

/* The thread will execute in this function */
void *runner(void *param)
{
  int i, upper = atoi(param);
  sum = 0;
  for (i = 1; i <= upper; i++)
  {
    sum += i;
    // usleep(1000); // Sleep for 1 millisecond
  }
  pthread_exit(0);
}
// Compile with: gcc -o pthread_example_sum_of_n pthread_example_sum_of_n.c -lpthread
// Run with: ./pthread_example_sum_of_n 1000000