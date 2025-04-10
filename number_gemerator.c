#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./number_gemerator size of gem\n");
        return 1;
    }

    int size = atoi(argv[1]);

    // First half (increasing)
    for (int i = 1; i <= size; i++)
    {
        // Print spaces
        for (int j = size; j > i; j--)
        {
            printf(" ");
        }

        // Print numbers
        for (int k = 1; k <= i * 2 - 1; k++)
        {
            printf("%d", k);
        }

        printf("\n");
    }

    // Second half (decreasing)
    for (int i = 1; i <= size - 1; i++)
    {
        // Print spaces
        for (int j = 1; j <= i; j++)
        {
            printf(" ");
        }

        // Print numbers
        for (int k = 1; k <= (size - i) * 2 - 1; k++)
        {
            printf("%d", k);
        }

        printf("\n");
    }

    return 0;
}