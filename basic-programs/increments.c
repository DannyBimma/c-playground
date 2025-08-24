#include <stdio.h>

int main(void)
{
    int a = 0;
    int b = 0;
    int c = a++ + ++b;

    printf("a: %d, b: %d, c: %d\n", a, b, c);

    return 0;
}