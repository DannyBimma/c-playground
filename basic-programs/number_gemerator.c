/*
 * Routine: A program that outputs a diamond made of
 * integers to the terminal
 * Author: DannyBimma
 * Copyright: (c) 2025 Technomancer Pirate Captain. All Rights Reserved.
 */

#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <number>\n", argv[0]);

    return 1;
  }

  // Parse <number> as a positive int with strtol for validation
  errno = 0;
  char *end = NULL;
  const char *arg = argv[1];
  long parsed = strtol(arg, &end, 10);

  // Detect parsing errors: overflow/underflow, no digits, or trailing chars
  if (errno == ERANGE || arg == end) {
    fprintf(stderr, "Error: invalid size '%s'\n", arg);

    return 2;
  }
  // Skip trailing spaces before validating end of string
  while (end && *end == ' ')
    end++;
  if (end && *end != '\0') {
    fprintf(stderr, "Error: unexpected characters after size: '%s'\n", end);

    return 2;
  }
  if (parsed < 1 || parsed > INT_MAX) {
    fprintf(stderr, "Error: size must be in range 1..%d\n", INT_MAX);

    return 2;
  }

  int size = (int)parsed;

  /*
   * UX warning if gem width exceeds terminal columns.
   * Diamond width is (2*size - 1). Use COLUMNS env if
   * present, else default 80.
   */
  int term_cols = 80;
  const char *cols_env = getenv("COLUMNS");

  if (cols_env && *cols_env) {
    char *cols_end = NULL;
    long cols_val = strtol(cols_env, &cols_end, 10);

    if (cols_end && (*cols_end == '\0' || *cols_end == '\n') && cols_val > 0 &&
        cols_val <= INT_MAX) {
      term_cols = (int)cols_val;
    }
  }

  // long to avoid intermediate overflow
  long width = (long)size * 2 - 1;

  if (width > term_cols) {
    fprintf(stderr,
            "Warning: output width (%ld) exceeds terminal columns (%d); lines "
            "may wrap.\n",
            width, term_cols);
  }

  // First half (increasing)
  for (int row = 1; row <= size; row++) {
    for (int space = 1; space <= size - row; space++)
      printf(" ");

    for (int num = 1; num <= row * 2 - 1; num++)
      printf("%d", num % 10); // maintain shape with larger numbers

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
