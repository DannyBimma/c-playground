#include <stdio.h>
#include <string.h>

int main(void) {
  char *s = "I am the man who will become The King of the Pirates!!!!";

  printf("The size of an int is: %lu\n", sizeof(int));
  printf("The size of an float is: %lu\n", sizeof(float));
  printf("The size of an char is: %lu\n", sizeof(char));
  printf("The size of an double is: %lu\n", sizeof(double));
  printf("The size of the string is: %lu\n", sizeof(s));
  printf("But the length of that same string is: %lu\n", strlen(s));

  return 0;
}
