#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./number_gemerator (size of gem)\n");
        return 1;
    }

    if (argc > 2)
    {
        printf("Usage: ./number_gemerator (size of gem)\n");
        printf("Error: Too many arguments\n");
        return 2;
    }

    int size = atoi(argv[1]);

    if (size > INT_MAX)
    {
        printf("Error: That thang is way too big for my 32-bit ass, baby 😮!!\n");
        return 69;
    }

    // First half (increasing)
    for (int row = 1; row <= size; row++)
    {
        for (int space = 1; space <= size - row; space++)
        {
            printf(" ");
        }

        for (int num = 1; num <= row * 2 - 1; num++)
        {
            printf("%d", num % 10); // To maintain shape with large numbers
        }

        printf("\n");
    }

    // Second half (decreasing)
    for (int row = 1; row <= size - 1; row++)
    {
        for (int space = 1; space <= row; space++)
        {
            printf(" ");
        }

        for (int num = 1; num <= (size - row) * 2 - 1; num++)
        {
            printf("%d", num % 10);
        }

        printf("\n");
    }

    return 0;
}