/*
 * CS50 Mario (less)
 *
 * Prints a right-aligned half-pyramid of height 1..8 using hashes (#).
 */

#include <cs50.h>
#include <stdio.h>

int main(void) {
  int height;

  // Prompt for height in the inclusive range [1, 8]
  do {
    height = get_int("Height: ");
  } while (height < 1 || height > 8);

  // Print pyramid rows
  for (int i = 0; i < height; i++) {
    // Leading spaces
    for (int k = i; k < (height - 1); k++) {
      printf(" ");
    }
    // Hashes
    for (int j = 0; j <= i; j++) {
      printf("#");
    }
    printf("\n");
  }

  return 0;
}
