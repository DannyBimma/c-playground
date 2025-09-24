/*
 * Routine: A command-line program that calculates rectangle area
 * and perimeter from width and height arguments with robust input
 * validation and error handling.
 * Author: DannyBimma
 * Copyright: (c) 2025 Technomancer Pirate Captain. All Rights Reserved.
 */

#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

// Prototypes
static int parse_double(const char *s, double *out);
static void print_correct_usage(const char *prog);

int main(int argc, char *argv[]) {
  double rect_width;
  double rect_height;
  double rect_perimeter;
  double rect_area;

  // Validate command-line args
  if (argc != 3) {
    print_correct_usage(argv[0]);

    return 1;
  }

  // Parse and validate width and height args
  int valid_width = parse_double(argv[1], &rect_width);
  int valid_height = parse_double(argv[2], &rect_height);

  // Handle parsing errors with specific error messages
  if (!valid_width || !valid_height) {
    if (!valid_width) {
      fprintf(stderr, "Invalid width: '%s'\n", argv[1]);
    }
    if (!valid_height) {
      fprintf(stderr, "Invalid height: '%s'\n", argv[2]);
    }
    print_correct_usage(argv[0]);

    return 1;
  }

  // Calculate rectangle measurements
  rect_perimeter = 2.0 * (rect_width + rect_height);
  rect_area = rect_width * rect_height;

  // Display results in formatted output
  printf("---RECTANGLE DIMENSIONS---\n");
  printf("\n");
  printf("HEIGHT: %.2lf\n", rect_height);
  printf("WIDTH: %.2lf\n", rect_width);
  printf("PERIMETER: %.2lf\n", rect_perimeter);
  printf("AREA: %.2lf\n", rect_area);

  return 0;
}

// Print usage instructions to stderr
static void print_correct_usage(const char *prog) {
  fprintf(stderr, "Usage: %s <width> <height>\n", prog);
  fprintf(stderr,
          "  width & height values must be numbers: (e.g. 420.28 & 69)\n");
}

// Top tier string to double conversion with validation
static int parse_double(const char *s, double *out) {
  if (s == NULL || *s == '\0')
    return 0; // null or empty string

  char *end = NULL;
  errno = 0;
  double v = strtod(s, &end);

  if (s == end)
    return 0; // no conversion occurred
  if (errno == ERANGE)
    return 0; // value out of range

  // Allow trailing white-space but reject other non-numeric chars
  while (end && *end != '\0' && isspace((unsigned char)*end))
    end++;
  if (end && *end != '\0')
    return 0; // extra non-numeric characters found

  *out = v; // store converted value

  return 1;
}
