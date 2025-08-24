#include <stdio.h>

typedef struct car
{
    char *make;
    char *model;
    char *chassis;
    char *engine;
    int hp;
    int torque;
    int year;
    int price;
} car_struct;

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

void init_whips(car_struct *car)
{
    car_struct my_whip;

    my_whip.make = "Ferrari";
    my_whip.model = "430 Scuderia";
    my_whip.chassis = "Carbon Fiber";
    my_whip.engine = "4.3L V8";
    my_whip.hp = 503;
    my_whip.torque = 347;
    my_whip.year = 2009;
}