#include <stdio.h>
#include <cs50.h>

int factorial(int n);

int main(void)
{
    int n = get_int("Input a number: ");
    printf("The factorial of %i is %i\n", n, factorial(n));
}

int factorial(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}