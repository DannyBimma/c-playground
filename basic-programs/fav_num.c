#include <stdio.h>

int main(void) {
  int favNum;

  printf("Please input your favourite number:\n");
  scanf("%d", &favNum);

  printf("Your favourite number squared is: %d\n", favNum * favNum);

  return 0;
}
