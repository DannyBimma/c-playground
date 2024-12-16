#include <stdio.h>
#include <string.h>

int main(void) 
{
    // Array to store 49 chars plus null terminator
    char name[50];

    // Print instruction to console  
    printf("Enter your name: ");
    // Read chars (49 max) from standard input
    fgets(name, 50, stdin);  
    
    // Remove the trailing newline from fgets
    name[strcspn(name, "\n")] = '\0';
    
    printf("Hello, %s!\n", name);
    return 0;
}