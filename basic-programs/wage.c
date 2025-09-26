/*
 * Routine: A program that calculates the amount of money paid to the
 * user on a weekly basis.
 * Author: DannyBimma
 * Copyright: (c) 2025 Technomancer Pirate Captain. All Rights Reserved.
 */

#include <stdio.h>

#define PAYRATE 12.00

// Prototypes
double calculate_tax(double wage);

int main(void) {
  double hrsWorked;
  double taxes;
  double grossPay;
  double netPay;

  // Get the amount of hrs worked
  printf("Enter number of hours worked this week:\t");
  scanf("%lf", &hrsWorked);

  // Calc basic pay & overtime before taxes
  if (hrsWorked > 40) {
    double overTimeRate = PAYRATE * 1.5;
    grossPay = (40 * PAYRATE) + ((hrsWorked - 40) * overTimeRate);
  } else {
    grossPay = hrsWorked * PAYRATE;
  }

  // Calculate taxes and net pay
  taxes = calculate_tax(grossPay);
  netPay = grossPay - taxes;

  printf("\nGross pay: $%.2f\n", grossPay);
  printf("Taxes: $%.2f\n", taxes);
  printf("Net pay: $%.2f\n", netPay);

  return 0;
}

double calculate_tax(double wage) {
  double tax = 0.0;

  // First $300 at 15%
  if (wage > 300) {
    tax += 300 * 0.15;
  } else {
    tax += wage * 0.15;
    return tax;
  }

  // Next $150 at 20%
  if (wage > 450) {
    tax += 150 * 0.20;
  } else {
    tax += (wage - 300) * 0.20;
    return tax;
  }

  // Rest at 25%
  tax += (wage - 450) * 0.25;

  return tax;
}
