#include <stdio.h>

int main(void) {
  signed char c = -5; // 8-bits
  int i = c;          // 32-bits

  // Output: -5
  printf("char c cast to int i = %d\n", i);

  return 0;
}
