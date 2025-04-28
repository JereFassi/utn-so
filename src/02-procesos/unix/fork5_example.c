#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid;
    pid = fork();
    if (pid < 0) {
        printf("Error al crear proceso\n");
    } else if (pid == 0) {
        printf("Soy el proceso hijo\n");
    } else {
        printf("Soy el proceso padre\n");
    }
    fork();
    fork();
    if (pid == 0){ 
        printf("Hola\n"); 
    } 
}