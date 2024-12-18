#include <stdio.h>
#include <string.h>

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
    
    // Check for positive or negative res val
    if (strcmp(res, "yes") == 0 || strcmp(res, "Yes") == 0 || strcmp(res, "YES") == 0 || strcmp(res, "y") == 0 || strcmp(res, "Y") == 0)
    {
        resVal = 0;
    }
    else if (strcmp(res, "no") == 0 || strcmp(res, "No") == 0 || strcmp(res, "NO") == 0 || strcmp(res, "n") == 0 || strcmp(res, "N") == 0)
    {
        resVal = 1;
    }
    else
    {
        printf("Invalid Response !!");
    }

    // Print msg for pos res
    if(resVal == 0)
    {
        printf("Welcome to the Matrix, my friend. We've been expecting you 😎 !!\n");
    }
    else
    {
        printf("You are not ready. You remain blind. Sad to see 😔 !!\n");
    }
    
    return 0;
}