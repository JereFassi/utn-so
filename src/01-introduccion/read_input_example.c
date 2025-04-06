#include <stdio.h>

int main() {
    char input[100]; // Buffer to store user input

    printf("Enter a value: ");
    if (fgets(input, sizeof(input), stdin) != NULL) {
        printf("You entered: %s", input);
    } else {
        printf("Error reading input.\n");
    }

    return 0;
}