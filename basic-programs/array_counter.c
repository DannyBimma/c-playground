/*
 * Routine: A program that counts occurrences of each digit
 * (0-9 with the count matched to their respective array index,
 * white space characters, and other misc characters from input.
 * Author: DannyBimma
 * Copyright: (c) 2025 Technomancer Pirate Captain. All Rights Reserved.
 */

#include <stdio.h>

int main(void) {
  int n_white = 0, n_other = 0;
  int n_digit[10];
  int c;

  // Zero out counter array
  for (int i = 0; i < 10; i++)
    n_digit[i] = 0;

  // Process each char from stdin until EOF
  while ((c = getchar()) != EOF) {
    if (c >= '0' && c <= '9')
      ++n_digit[c - '0']; // increment counter for this specific digit
    else if (c == ' ' || c == '\n' || c == '\t')
      ++n_white;
    else
      ++n_other;
  }

  // Print results
  printf("digits = ");

  for (int i = 0; i < 10; i++)
    printf(" %d", n_digit[i]);

  printf(", white space = %d, other = %d\n", n_white, n_other);

  return 0;
}
