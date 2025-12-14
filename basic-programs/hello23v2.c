#include <stdio.h>
#include <stdlib.h>

int main() {
  // Super safe "hello, world."
  if (puts("Hello, world!") == EOF)
    return EXIT_FAILURE;

  return EXIT_SUCCESS;
}
