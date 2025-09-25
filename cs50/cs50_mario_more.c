#include <stdbool.h>
#include <stdio.h>

int main(void) {
  int height;
  bool valid_input = false;

  // Input validation
  do {
    printf("Height: ");
    if (scanf("%d", &height) == 1) {
      if (height >= 1 && height <= 8) {
        valid_input = true;
      }
    }
    // Clear input buffer
    while (getchar() != '\n')
      ;
  } while (!valid_input);

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
