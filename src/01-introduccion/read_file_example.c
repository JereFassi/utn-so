#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main() {
    FILE *file;
    char buffer[BUFFER_SIZE];
    
    // Open file
    file = fopen("src/01-introduccion/tuc.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    printf("Contenido del archivo TUC.txt:\n");
    printf("--------------------------------\n");

    // Read and print file content
    while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
        printf("%s", buffer);
    }

    // Close file
    if (fclose(file) != 0) {
        perror("Error closing file");
        return 1;
    }

    return 0;
}