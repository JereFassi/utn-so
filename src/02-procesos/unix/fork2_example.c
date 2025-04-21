#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main() {
    pid_t pid;
    int status;

    printf("Parent process (PID: %d) starting...\n", getpid());

    for (int i = 0; i < 3; i++) {
        pid = fork();
        
        if (pid < 0) {
            fprintf(stderr, "Fork failed\n");
            exit(1);
        } else if (pid == 0) {
            printf("Child process %d (PID: %d, Parent PID: %d) starting...\n", i + 1, getpid(), getppid());
            sleep(2);
            exit(0);
        }
    }

    // Parent waits for all children
    while ((pid = wait(&status)) > 0) {
        printf("Child process (PID: %d) finished with status %d\n", pid, WEXITSTATUS(status));
    }

    return 0;
}