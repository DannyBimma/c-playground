// So I tried to implement CS50's Mario on my own, on my machine.
// But apparently some things would need to be installed on my system?
// Long story short I am currently too stupid to get whatever the fuck
// installed so the code could compile and run.
// So instead, I just asked Claude to rewrite it for me without using
// the CS50 library so maybe i can look back on this code in 85 years 
// and actually what the actual fuck line 19 is doing 😭!!

#include <stdio.h>

int main(void)
{
    int block_h, block_w;
    
    printf("Input block height: ");
    while (scanf("%d", &block_h) != 1 || block_h <= 0)
    {
        // Clear input buffer in case of invalid input
        while (getchar() != '\n');
        printf("Please enter a valid positive number for height: ");
    }
    
    printf("Input block width: ");
    while (scanf("%d", &block_w) != 1 || block_w <= 0)
    {
        while (getchar() != '\n');
        printf("Please enter a valid positive number for width: ");
    }
    
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