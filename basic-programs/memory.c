/*
 * Routine: A program demonstrating memory concepts including
 * pointer addresses, string literals, and struct definitions.
 * Author: DannyBimma
 * Copyright: (c) 2025 Technomancer Pirate Captain. All Rights Reserved.
 */

#include <stdio.h>

// Structure to represent a car with various attributes
typedef struct car {
  char *make;
  char *model;
  char *chassis;
  char *engine;
  int hp;
  int torque;
  int year;
  int price;
} car_struct;

int main(void) {
  char *s = "Hello, world!"; // pointer to string literal

  // Demonstrate memory addresses and pointer concepts
  printf("The string is: %s\n", s);

  // Print address where string literal is stored
  printf("The address of the string is: %p\n", s);

  // Print address of the pointer variable itself
  printf("The address of the pointer is: %p\n", &s);

  return 0;
}

// Function to initialise a car structure (incomplete)
void init_whips(car_struct *car) {
  car_struct my_whip; // local car instance

  // Initialise car attributes
  my_whip.make = "Ferrari";
  my_whip.model = "430 Scuderia";
  my_whip.chassis = "Carbon Fiber";
  my_whip.engine = "4.3L V8";
  my_whip.hp = 503;
  my_whip.torque = 347;
  my_whip.year = 2009;
  // TODO: price not set, and local struct not copied to parameter
}
