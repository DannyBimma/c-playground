#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() 
{
    char name[50];
    char res[4];

  
  // Get and format inital user input
    printf("Enter your name: "); 

    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove new line from fgets
    
    printf("Hello, %s!\n", name);

    // Print "the question" and format user input
    printf("Do you believe? \n");

    fgets(res, sizeof(res), stdin);
    res[strcspn(res, "\n")] = '\0';
    
    for (int i = 0; res[i]; i++) 
    {
        res[i] = tolower(res[i]);
    }

    // Validate input and print msg
    if (strcmp(res, "yes") == 0 || strcmp(res, "y") == 0) 
    {
        printf("Welcome to the Matrix, %s. We've been expecting you 😎 !!\n", name);
    } 
    else if (strcmp(res, "no") == 0 || strcmp(res, "n") == 0) 
    {
        printf("You are not ready, %s. You remain blind. Sad to see 😔 !!\n", name);
    } 
    else 
    {
        printf("Invalid Response !!\n");
        return 1;
    }

    return 0;
}