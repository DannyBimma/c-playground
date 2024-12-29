#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int block_h = 3;
    int block_w = 3;

    for(int i = 0; i < block_h; i++)
    {
        for(int j = 0; j < block_w; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}