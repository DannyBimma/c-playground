#include <stdio.h>
#include <string.h>

int main(void) {
  char *s = "I am the man who will become The King of the Pirates!!!!";

  printf("The size of an int is: %lu\n", sizeof(int));
  printf("The size of a float is: %lu\n", sizeof(float));
  printf("The size of a long is: %lu\n", sizeof(long));
  printf("The size of a long long is: %lu\n", sizeof(long long));
  printf("The size of a double is: %lu\n", sizeof(double));
  printf("The size of a long double is: %lu\n", sizeof(long double));
  printf("The size of a char is: %lu\n", sizeof(char));
  printf("The string s is: %s\n", s);
  printf("The size of the string s is: %lu\n", sizeof(s));
  printf("But the length of string s is: %lu\n", strlen(s));

  return 0;
}
