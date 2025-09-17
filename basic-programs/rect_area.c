#include <stdio.h>

int main(void) {
  double rect_width = 420.69;
  double rect_height = 69.42;
  double rect_perimeter;
  double rect_area;

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
