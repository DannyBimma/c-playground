#include <stdio.h>
#include <cs50.h>
// int get_int(const char *input);


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