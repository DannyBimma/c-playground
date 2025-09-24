/*
 * Routine: A program that prompts user for block dimensions
 * to print a rectangular block comprised of the '#' character.
 * Author: DannyBimma
 * Copyright: (c) 2025 Technomancer Pirate Captain. All Rights Reserved.
 */

#include <stdio.h>

// Prototypes
int get_int(const char *input);
int block_h, block_w; // global variables for block dimensions

int main(void) {
  // Get block dimensions from user
  block_h = get_int("Input Block Height: ");
  block_w = get_int("Input Block Width: ");

  // Validate dimensions
  if (block_h <= 0 || block_w <= 0) {
    printf("Sorry: Ivalid Block Size!!\n");
    printf("Please try again with a number greater than 0 🫡\n");

    return 0;
  }

  // Print block: outer loop for rows, inner loop for columns
  for (int i = 0; i < block_h; i++) {
    for (int j = 0; j < block_w; j++)
      printf("#"); // print a '#' for each column in row

    printf("\n"); // end of row, move to next line
  }

  return 0;
}

// Prompt user and read integer input
int get_int(const char *input) {
  int num;

  printf("%s", input); // display prompt
  scanf("%d", &num);   // read integer from user

  return num;
}
