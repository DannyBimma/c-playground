#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./number_gemerator size of gem\n");
        return 1;
    }

    int size = atoi(argv[1]);

    // First half (increasing)
    for (int row = 1; row <= size; row++)
    {
        // Leading spaces
        for (int space = 1; space <= size - row; space++)
        {
            printf(" ");
        }

        // Numbers in ascending order
        for (int num = 1; num <= row * 2 - 1; num++)
        {
            printf("%d", num % 10); // Maintain shape with larger numbers
        }

        printf("\n");
    }

    // Second half (decreasing)
    for (int row = 1; row <= size - 1; row++)
    {
        // Leading spaces
        for (int space = 1; space <= row; space++)
        {
            printf(" ");
        }

        // Numbers in ascending order
        for (int num = 1; num <= (size - row) * 2 - 1; num++)
        {
            printf("%d", num % 10);
        }

        printf("\n");
    }

    return 0;
}