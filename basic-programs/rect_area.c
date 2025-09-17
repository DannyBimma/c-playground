#include <stdio.h>

int main(void) {
  double rect_width = 420.0;
  double rect_height = 69.0;
  double rect_perimeter;
  double rect_area;

  rect_perimeter = 2 * (rect_width + rect_height);
  rect_area = rect_width * rect_height;

  printf("---RECTANGLE DIMENSIONS---\n");
  printf("\n");
  printf("HEIGHT: %lf\n", rect_height);
  printf("WIDTH: %lf\n", rect_width);
  printf("PERIMETER: %lf\n", rect_perimeter);
  printf("AREA: %lf\n", rect_area);

  return 0;
}
