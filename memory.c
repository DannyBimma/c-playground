#include <stdio.h>

int main(void)
{
    char *s = "Hello, world!";
    printf("%s\n", s);
    printf("%p\n", s);
    printf("%p\n", &s);
}