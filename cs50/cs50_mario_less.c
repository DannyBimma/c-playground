#include <cs50.h>
#include <limits.h> // IDK, seems like a good idea for mem safety
#include <stdio.h>

int main(void) {
  int height;

  // Prompt user for a number between 1 and... the end of a 32-bit integer
  // 🤷🏽‍♂️?
  do {
    height = get_int("HEIGHT: ");
  } while (height < 1 || height > INT_MAX);

  // Print pyramid rows based height
  for (int i = 0; i < height; i++) {

    // Print spaces for each row (1-less than height)
    for (int k = i; k < (height - 1); k++) {
      printf(" ");
    }

    // Print pyramid colums based on row interation
    for (int j = 0; j <= i; j++) {
      printf("#");
    }

    // Escape to new line
    printf("\n");
  }
}
