#include <stdio.h>
#include <string.h>

int main() 
{
    // Init input strings (50 and 4 chars max)
    char name[50];
    char res[4];

    // Set res val
    int resVal;

    // Get user input for name  
    printf("Enter your name: ");
    // Read chars (49 max) from std input
    fgets(name, 50, stdin);  
    
    // Remove the trailing newline from fgets
    name[strcspn(name, "\n")] = '\0';
    
    printf("Hello, %s!\n", name);

    // Ask user the question and format res
    printf("Do you believe? \n");
    fgets(res, 4, stdin);

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