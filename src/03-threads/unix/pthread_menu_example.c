#include <pthread.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CHOICE_LEN 16

volatile int running = 1;

void *input_thread(void *param);
void *action_worker(void *param);

typedef struct
{
  char choice[MAX_CHOICE_LEN];
} action_arg_t;

int main()
{
  pthread_t tid_input;
  pthread_create(&tid_input, NULL, input_thread, NULL);
  pthread_join(tid_input, NULL);
  return 0;
}

void *input_thread(void *param)
{
  while (running)
  {
    printf("\n=== Menú ===\n");
    printf("1. Acción   1\n");
    printf("2. Acción   2\n");
    printf("3. Ayuda    h\n");
    printf("q. Salir     \n");
    printf("Elige una opción: ");
    fflush(stdout);

    char buffer[MAX_CHOICE_LEN];
    if (fgets(buffer, sizeof(buffer), stdin) == NULL)
    {
      continue;
    }
    buffer[strcspn(buffer, "\n")] = 0; // Remove newline

    if (strcmp(buffer, "q") == 0)
    {
      printf("Saliendo...\n");
      running = 0;
      break;
    }

    // Allocate and copy the choice for the worker thread
    action_arg_t *arg = malloc(sizeof(action_arg_t));
    strncpy(arg->choice, buffer, MAX_CHOICE_LEN);

    pthread_t tid_worker;
    pthread_create(&tid_worker, NULL, action_worker, arg);
    pthread_detach(tid_worker); // Detach so resources are freed automatically
  }
  return NULL;
}

void *action_worker(void *param)
{
  action_arg_t *arg = (action_arg_t *)param;
  if (strcmp(arg->choice, "1") == 0)
  {
    printf("Ejecutando Acción 1...\n");
    usleep(10000000); // 10 seconds delay
    printf("Acción 1 finalizada.\n");
  }
  else if (strcmp(arg->choice, "2") == 0)
  {
    printf("Ejecutando Acción 2...\n");
    usleep(20000000); // 20 seconds delay
    printf("Acción 2 finalizada.\n");
  }
  else if (strcmp(arg->choice, "h") == 0)
  {
    printf("Ayuda: Elige una opción del menú.\n");
  }
  else
  {
    printf("Opción no válida.\n");
  }
  free(arg);
  return NULL;
}

// Compile with: gcc -o pthread_menu_example pthread_menu_example.c -lpthread
// Run with: ./pthread_menu_example