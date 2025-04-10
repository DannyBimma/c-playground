#include <stdio.h>

int main()
{
    int size = 5;

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