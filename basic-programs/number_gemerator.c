#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: ./number_gemerator (<number>)\n");

    return 1;
  }

  if (argc > 2) {
    printf("Error: Too many arguments\n");
    printf("Usage: ./number_gemerator (<number>)\n");

    return 2;
  }

  int size = atoi(argv[1]);

  if (size > INT_MAX) {
    printf("Error: That thang way too big for this 32-bit ass, baby 😮!!\n");

    return 69;
  } else if (size > 66) {
    // TODO: Unsure if it's a limit of the viewport or just bad code logic
    printf("Output may be wonky, this is the upper limit of the gems 💎\n");
  } else if (size < 1) {
    printf("Error: Size must be greater than 0\n");

    return 3;
  }

  // First half (increasing)
  for (int row = 1; row <= size; row++) {
    for (int space = 1; space <= size - row; space++)
      printf(" ");

    for (int num = 1; num <= row * 2 - 1; num++)
      printf("%d", num % 10); // Maintain shape with larger numbers

    printf("\n");
  }

  // Second half (decreasing)
  for (int row = 1; row <= size - 1; row++) {
    for (int space = 1; space <= row; space++)
      printf(" ");

    for (int num = 1; num <= (size - row) * 2 - 1; num++)
      printf("%d", num % 10);

    printf("\n");
  }

  return 0;
}
