#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() 
{
    char name[50]; // Init input strings (50 and 4 chars max)
    char res[4];
    int resVal = -1; // Init res val
  
    printf("Enter your name: "); // Get user input
    fgets(name, sizeof(name), stdin); // Read chars (49 max) from std input
    name[strcspn(name, "\n")] = '\0'; // Remove new line from fgets
    
    printf("Hello, %s!\n", name);

    // Ask user the question and format input
    printf("Do you believe? \n");
    fgets(res, sizeof(res), stdin);
    res[strcspn(res, "\n")] = '\0';
    
    // Convert input to lowercase
    for (int i = 0; res[i]; i++) 
    {
        res[i] = tolower(res[i]);
    }

    // Validate res
    if (strcmp(res, "yes") == 0 || strcmp(res, "y") == 0) 
    {
        resVal = 1;
    } 
    else if (strcmp(res, "no") == 0 || strcmp(res, "n") == 0) 
    {
        resVal = 0;
    } 
    else 
    {
        printf("Invalid Response !!\n");
        return 1;
    }

    // Print custom msg for res
    if(resVal == 1)
    {
        printf("Welcome to the Matrix, %s. We've been expecting you 😎 !!\n", name);
    }
    else
    {
        printf("You are not ready, %s. You remain blind. Sad to see 😔 !!\n", name);
    }
    
    return 0;
}