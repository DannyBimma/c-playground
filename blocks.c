#include <stdio.h>

int main(void)
{
    int block_h, block_w;
    
    // Get height input
    printf("Input block height: ");
    while (scanf("%d", &block_h) != 1 || block_h <= 0)
    {
        // Clear input buffer in case of invalid input
        while (getchar() != '\n');
        printf("Please enter a valid positive number for height: ");
    }
    
    // Get width input
    printf("Input block width: ");
    while (scanf("%d", &block_w) != 1 || block_w <= 0)
    {
        while (getchar() != '\n');
        printf("Please enter a valid positive number for width: ");
    }
    
    // Print the block pattern
    for (int i = 0; i < block_h; i++)
    {
        for (int j = 0; j < block_w; j++)
        {
            printf("#");
        }
        printf("\n");
    }
    
    return 0;
}