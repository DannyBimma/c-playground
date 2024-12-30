#include <stdio.h>

int get_int(const char *input);
int block_h, block_w;

int main(void)
{
    block_h = get_int("Input Block Height: ");
    block_w = get_int("Input Block Width: ");

    if(block_h <= 0 || block_w <= 0)
    {
        printf("Sorry: Ivalid Block Size!!\n");
        printf("Please try again with a number greater than 0 🫡\n");

        return 0;
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


int get_int(const char *input)
{
    int num;
    printf("%s", input);
    scanf("%d", &num);
    
    return num;
}