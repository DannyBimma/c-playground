#include <stdio.h>

int get_int(const char *input);

// Fix the logic memory mess in this pile of shit later, bro 🙄!! 
int main(void)
{
    int arr_len = get_int("How many numbers would you like to average? \n");
    int avg_arr[arr_len];
    int num_sum = 0;

    for(int i = 0; i < arr_len; i++)
    {
        avg_arr[i] = get_int("Enter the number \n");
        num_sum += avg_arr[i];
    }

    int avg = num_sum / arr_len;

    printf("The average of those numbers is: %i\n", avg);

    return 0;
}

int get_int(const char *input)
{
    int num;
    printf("%s", input);
    scanf("%d", &num);
    
    return num;
}