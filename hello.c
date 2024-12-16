#include <stdio.h>
#include <string.h>

int main() {
    char name[50];  // Array to store up to 49 characters plus null terminator
    printf("Enter your name: ");
    fgets(name, 50, stdin);  // Read up to 49 characters from standard input
    
    // Remove the trailing newline that fgets keeps
    name[strcspn(name, "\n")] = '\0';
    
    printf("Hello, %s!\n", name);
    return 0;
}