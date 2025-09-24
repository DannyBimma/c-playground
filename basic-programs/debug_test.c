#include <stdio.h>

int multiply(int a, int b) {
  int result = a * b;

  return result; // breakpoint
}

int main() {
  int x = 5;
  int y = 7;
  int product = multiply(x, y);

  printf("Result: %d\n", product);

  return 0;
}
