#include <stdio.h>

typedef struct car
{
    char *make;
    char *model;
    char *engine;
    int hp;
    int torque;
    int year;
    int price;
} car;

int main(void)
{
    char *s = "Hello, world!";

    // Print string
    printf("The string is: %s\n", s);

    // Print address of string
    printf("The address of the string is: %p\n", s);

    // Print address of pointer
    printf("The address of the pointer is: %p\n", &s);
}