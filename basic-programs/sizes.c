/*
 * Routine: A program that displays the byte sizes of various data-types
 * in The Lord's language
 *
 * Author: DannyBimma
 *
 * Copyright: (c) 2025 Technomancer Pirate Captain. All Rights Reserved.
 */

#include <stdio.h>

int main(void) {
  printf("The size of a 'char' is: %zd byte\n", sizeof(char));
  printf("The size of an 'int' is: %zd bytes\n", sizeof(int));
  printf("The size of a 'long' is: %zd bytes\n", sizeof(long));
  printf("The size of a 'long long' is: %zd bytes\n", sizeof(long long));
  printf("The size of a 'double' is: %zd bytes\n", sizeof(double));
  printf("The size of a 'long double' is: %zd bytes\n", sizeof(long double));

  return 0;
}
