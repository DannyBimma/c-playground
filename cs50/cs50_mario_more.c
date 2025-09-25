/*
 * CS50 Mario (more)
 *
 * Prints a double half-pyramid of height 1..8 with a two-space gap between
 * the pyramids, using hashes (#).
 */

#include <cs50.h>
#include <stdio.h>

int main(void) {
  int height;

  // Prompt for height in the inclusive range [1, 8]
  do {
    height = get_int("Height: ");
  } while (height < 1 || height > 8);

  // Pyramid scheme
  for (int i = 1; i <= height; i++) {
    // Print preceding spaces
    for (int j = 0; j < height - i; j++) {
      printf(" ");
    }

    // Print first pyramid
    for (int j = 0; j < i; j++) {
      printf("#");
    }

    // Print gap between pyramids
    printf("  ");

    // Print second pyramid
    for (int j = 0; j < i; j++) {
      printf("#");
    }

    printf("\n");
  }

  return 0;
}
