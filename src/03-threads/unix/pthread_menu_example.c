#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CHOICE_LEN 16

volatile int running = 1;
char user_choice[MAX_CHOICE_LEN];
pthread_mutex_t choice_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t choice_cond = PTHREAD_COND_INITIALIZER;

void *input_thread(void *param);
void *action_thread(void *param);

int main()
{
    pthread_t tid_input, tid_action;

    pthread_create(&tid_input, NULL, input_thread, NULL);
    pthread_create(&tid_action, NULL, action_thread, NULL);

    pthread_join(tid_input, NULL);
    pthread_join(tid_action, NULL);

    return 0;
}

void *input_thread(void *param)
{
    while (running)
    {
        printf("\n=== Menú ===\n");
        printf("1. Acción 1\n");
        printf("2. Acción 2\n");
        printf("q. Salir\n");
        printf("Elige una opción: ");
        fflush(stdout);

        char buffer[MAX_CHOICE_LEN];
        if (fgets(buffer, sizeof(buffer), stdin) == NULL)
        {
            continue;
        }
        buffer[strcspn(buffer, "\n")] = 0; // Remove newline

        pthread_mutex_lock(&choice_mutex);
        strncpy(user_choice, buffer, MAX_CHOICE_LEN);
        pthread_cond_signal(&choice_cond);
        pthread_mutex_unlock(&choice_mutex);

        if (strcmp(buffer, "q") == 0)
        {
            running = 0;
            break;
        }
    }
    return NULL;
}

void *action_thread(void *param)
{
    while (running)
    {
        pthread_mutex_lock(&choice_mutex);
        pthread_cond_wait(&choice_cond, &choice_mutex);

        if (strcmp(user_choice, "1") == 0)
        {
            printf("Ejecutando Acción 1...\n");
        }
        else if (strcmp(user_choice, "2") == 0)
        {
            printf("Ejecutando Acción 2...\n");
        }
        else if (strcmp(user_choice, "q") == 0)
        {
            printf("Saliendo...\n");
            running = 0;
        }
        else
        {
            printf("Opción no válida.\n");
        }

        pthread_mutex_unlock(&choice_mutex);
    }
    return NULL;
}

// Compile with: gcc -o pthread_menu_example pthread_menu_example.c -lpthread
// Run with: ./pthread_menu_example