#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void obtainMasterPassword(char buffer[], const size_t size) {
    printf("Enter master password: ");
    fflush(stdout);

    const int n = size > INT_MAX ? INT_MAX : (int)size; // Ensure size fits in int

    if (fgets(buffer, n, stdin) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0'; // remove newline character
    }
}

int main(void) {
    char masterPassword[128];

    puts("Welcome to the Password Manager!");

    obtainMasterPassword(masterPassword, sizeof(masterPassword));
    memset(masterPassword, 0, sizeof(masterPassword));
    return 0;
}