#include <stdio.h>
#include <pthread.h>
#include <time.h>

#define MAX 10 /* how many numbers to produce */

pthread_mutex_t the_mutex;   /* used for mutual exclusion */
pthread_cond_t condc, condp; /* used for signaling */

int buffer = 0; /* buffer used between producer and consumer */

/* producer and consumer are the two threads */
void *producer(void *ptr) /* produce data */
{
  int i;
  for (i = 1; i <= MAX; i++)
  {
    pthread_mutex_lock(&the_mutex); /* get exclusive access to buffer */
    while (buffer != 0)
      pthread_cond_wait(&condp, &the_mutex);
    printf("[Producer] Producing value: %d\n", i);
    buffer = i; /* put item in buffer */
    printf("[Producer] Buffer filled with value: %d\n", buffer);
    pthread_cond_signal(&condc);      /* wake up consumer */
    pthread_mutex_unlock(&the_mutex); /* release access to buffer */
  }
  printf("[Producer] Finished producing.\n");
  pthread_exit(0);
}

/* consumer and producer are the two threads */
void *consumer(void *ptr) /* consume data */
{
  int i;
  for (i = 1; i <= MAX; i++)
  {
    pthread_mutex_lock(&the_mutex); /* get exclusive access to buffer */
    while (buffer == 0)
      pthread_cond_wait(&condc, &the_mutex);
    printf("[Consumer] Consuming value: %d\n", buffer);
    buffer = 0; /* take item out of buffer */
    printf("[Consumer] Buffer emptied.\n");
    pthread_cond_signal(&condp);      /* wake up producer */
    pthread_mutex_unlock(&the_mutex); /* release access to buffer */
  }
  printf("[Consumer] Finished consuming.\n");
  pthread_exit(0);
}

/* main function */
int main(int argc, char **argv)
{
  pthread_t pro, con;
  pthread_mutex_init(&the_mutex, 0);
  pthread_cond_init(&condc, 0);
  pthread_cond_init(&condp, 0);

  struct timespec start, end;
  double elapsed;

  printf("[Main] Starting producer and consumer threads...\n");

  // Start timing
  clock_gettime(CLOCK_MONOTONIC, &start);

  pthread_create(&con, 0, consumer, 0);
  pthread_create(&pro, 0, producer, 0);
  pthread_join(pro, 0);
  pthread_join(con, 0);

  // End timing
  clock_gettime(CLOCK_MONOTONIC, &end);

  elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
  printf("[Main] Execution time: %.6f seconds\n", elapsed);

  printf("[Main] Both threads finished. Cleaning up...\n");
  pthread_cond_destroy(&condc);
  pthread_cond_destroy(&condp);
  pthread_mutex_destroy(&the_mutex);
  printf("[Main] Done.\n");
}
