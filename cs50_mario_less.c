#include <stdio.h>
#include <stdbool.h>
#include <limits.h> // for INT_MAX macro

// Helper funcs
void print_rows(int i, int h);
bool int_validator(int input);
int get_int(const char *input);


int main(void)
{
    int height;

    // Validate input
    do
    {
        height = get_int("HEIGHT: ");
    }
    while (int_validator(height));

    // print pyramid based height
    for (int i = 0; i < height; i++)
    {
        print_rows(i, height);

        printf("\n");
    }
}



// Use "height" input to print a row of spaces 1-less than the block's height
// Print a "#" at the end of each row of spaces
// Create the pyramid effect ☺️
void print_rows(int i, int h)
{
    for (int j = i; j < (h - 1); j++)
    {
        printf(" ");
    }

    for (int k = 0; k <= i; k++)
    {
        printf("#");
    }
}

// Check dem fools input son
bool int_validator(int input)
{
    if (input <= 0 || input >= INT_MAX)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Get user input of type int
int get_int(const char *input)
{
    int num;
    printf("%s", input);
    scanf("%d", &num);
    
    return num;
}