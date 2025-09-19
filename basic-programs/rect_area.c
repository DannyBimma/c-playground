#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

// Helper prototypes
static int parse_double(const char *s, double *out);
static void print_correct_usage(const char *prog);

int main(int argc, char *argv[]) {
  double rect_width;
  double rect_height;
  double rect_perimeter;
  double rect_area;

  if (argc != 3) {
    print_correct_usage(argv[0]);

    return 1;
  }

  int valid_width = parse_double(argv[1], &rect_width);
  int valid_height = parse_double(argv[2], &rect_height);

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

  rect_perimeter = 2.0 * (rect_width + rect_height);
  rect_area = rect_width * rect_height;

  printf("---RECTANGLE DIMENSIONS---\n");
  printf("\n");
  printf("HEIGHT: %.2lf\n", rect_height);
  printf("WIDTH: %.2lf\n", rect_width);
  printf("PERIMETER: %.2lf\n", rect_perimeter);
  printf("AREA: %.2lf\n", rect_area);

  return 0;
}

static void print_correct_usage(const char *prog) {
  fprintf(stderr, "Usage: %s <width> <height>\n", prog);
  fprintf(stderr,
          "  width & height values must be numbers: (e.g. 420.28 & 69)\n");
}

static int parse_double(const char *s, double *out) {
  if (s == NULL || *s == '\0')
    return 0;

  char *end = NULL;
  errno = 0;
  double v = strtod(s, &end);

  if (s == end)
    return 0; // no conversion
  if (errno == ERANGE)
    return 0; // out of range

  // Allow trailing white-space
  while (end && *end != '\0' && isspace((unsigned char)*end))
    end++;
  if (end && *end != '\0')
    return 0; // extra non-numeric chars

  *out = v; // integers become floating-point naturally

  return 1;
}
