/*
 * Routine: A program that calculates the amount of money paid to the
 * user on a weekly basis.
 * Author: DannyBimma
 * Copyright: (c) 2025 Technomancer Pirate Captain. All Rights Reserved.
 */

#include <stdio.h>

#define PAYRATE 12.00

int main(void) {
  int hrsWorked;
  int taxes;
  int grossPay;
  int netPay;

  // Get the amount of hrs worked
  printf("Enter number of hours worked this week:\t");
  scanf("%d", &hrsWorked);

  grossPay = hrsWorked * PAYRATE;

  printf("\nGross pay: %d\n", grossPay);

  return 0;
}
