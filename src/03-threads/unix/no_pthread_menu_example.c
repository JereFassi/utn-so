#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CHOICE_LEN 16

int main()
{
  int running = 1;
  char buffer[MAX_CHOICE_LEN];

  while (running)
  {
    printf("\n=== Menú ===\n");
    printf("1. Acción   1\n");
    printf("2. Acción   2\n");
    printf("3. Ayuda    h\n");
    printf("q. Salir     \n");
    printf("Elige una opción: ");
    fflush(stdout);

    if (fgets(buffer, sizeof(buffer), stdin) == NULL)
    {
      continue;
    }
    buffer[strcspn(buffer, "\n")] = 0; // Remove newline

    if (strcmp(buffer, "1") == 0)
    {
      printf("Ejecutando Acción 1...\n");
      usleep(10000000); // 10 seconds delay
    }
    else if (strcmp(buffer, "2") == 0)
    {
      printf("Ejecutando Acción 2...\n");
      usleep(20000000); // 20 seconds delay
    }
    else if (strcmp(buffer, "h") == 0)
    {
      printf("Ayuda: Elige una opción del menú.\n");
    }
    else if (strcmp(buffer, "q") == 0)
    {
      printf("Saliendo...\n");
      running = 0;
    }
    else
    {
      printf("Opción no válida.\n");
    }
  }

  return 0;
}

// Compile with: gcc -o menu_no_threads_example menu_no_threads_example.c
// Run with: ./menu_no_threads_example