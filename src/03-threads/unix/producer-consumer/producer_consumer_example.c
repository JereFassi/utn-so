#include <stdio.h>
#include <pthread.h>

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
    buffer = i;                       /* put item in buffer */
    pthread_cond_signal(&condc);      /* wake up consumer */
    pthread_mutex_unlock(&the_mutex); /* release access to buffer */
  }
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
    buffer = 0;                       /* take item out of buffer */
    pthread_cond_signal(&condp);      /* wake up producer */
    pthread_mutex_unlock(&the_mutex); /* release access to buffer */
  }
  pthread_exit(0);
}

/* main function */
int main(int argc, char **argv)
{
  pthread_t pro, con;
  pthread_mutex_init(&the_mutex, 0);
  pthread_cond_init(&condc, 0);
  pthread_cond_init(&condp, 0);
  pthread_create(&con, 0, consumer, 0);
  pthread_create(&pro, 0, producer, 0);
  pthread_join(pro, 0);
  pthread_join(con, 0);
  pthread_cond_destroy(&condc);
  pthread_cond_destroy(&condp);
  pthread_mutex_destroy(&the_mutex);
}