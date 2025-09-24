#include <stdio.h>

int main(void) {
  __uint128_t val;

  printf("The size of an int is: %lu\n", sizeof(int));
  printf("The size of a float is: %lu\n", sizeof(float));
  printf("The size of a long is: %lu\n", sizeof(long));
  printf("The size of a long long is: %lu\n", sizeof(long long));
  printf("The size of a double is: %lu\n", sizeof(double));
  printf("The size of a long double is: %lu\n", sizeof(long double));
  printf("uint128 var is: %lu\n", sizeof(val));

  return 0;
}
