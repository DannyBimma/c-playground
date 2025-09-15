/*
 * Author: DannyBimma
 * Purpose: Find the square of your favourite number.
 * Copyright (c) 2025 DannyBimma. All Rights Reserved.
 */
#include <stdio.h>

int main(void) {
  int favNum;
  _Bool successExit = 0; // C89 bools

  printf("Please input your favourite number:\n");
  scanf("%d", &favNum);

  printf("Your favourite number squared is: %d\n", favNum * favNum);
  printf("\nProgram ran successfully with exit code: %d\n\n", successExit);

  return successExit;
}
