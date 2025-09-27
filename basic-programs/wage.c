/*
 * Routine: A program that calculates the amount of money paid to the
 * user on a weekly basis.
 * Author: DannyBimma
 * Copyright: (c) 2025 Technomancer Pirate Captain. All Rights Reserved.
 */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PAYRATE 12.00
#define OVERTIME 40
#define TIME_AND_A_HALF 1.5
#define MAX_WEEK_HOURS 168.0

// Prototypes
double calculate_tax(double wage);

int main(void) {
  double hrsWorked = 0.0;
  double taxes;
  double grossPay;
  double netPay;

  // Get the amount of hrs worked and validate
  for (;;) {
    char buf[256];

    printf("Enter the number of hours you worked this week:\t");

    if (!fgets(buf, sizeof buf, stdin)) {
      fprintf(stderr, "\nError: Failed to read input.\n");

      return 1;
    }

    // If input line exceeds buffer, flush the remainder
    if (strchr(buf, '\n') == NULL) {
      int ch;

      while ((ch = getchar()) != '\n' && ch != EOF) {
        ;
      }
    }

    errno = 0;
    char *endptr = NULL;
    double val = strtod(buf, &endptr);

    /*Comprehensive checks for robust input validation*/
    if (endptr == buf) {
      fprintf(stderr, "Invalid input: please enter a numeric value.\n");
      continue;
    }
    if (errno == ERANGE) {
      fprintf(stderr, "Invalid input: number out of range.\n");
      continue;
    }

    // Skip trailing white-space
    while (*endptr == ' ' || *endptr == '\t' || *endptr == '\n' ||
           *endptr == '\r' || *endptr == '\v' || *endptr == '\f') {
      endptr++;
    }
    // Gobbledegook dismissal
    if (*endptr != '\0') {
      fprintf(stderr, "Invalid input: unexpected characters after number.\n");
      continue;
    }
    // Reality check for hours worked
    if (val <= 0.0) {
      fprintf(stderr, "Invalid input: hours must be greater than 0.\n");
      continue;
    }
    if (val > MAX_WEEK_HOURS) {
      fprintf(stderr, "Invalid input: hours cannot exceed %.0f in a week.\n",
              MAX_WEEK_HOURS);
      continue;
    }

    hrsWorked = val;

    break;
  }

  // Calc basic pay & overtime before taxes
  if (hrsWorked > OVERTIME) {
    double overTimeRate = PAYRATE * TIME_AND_A_HALF;
    grossPay = (OVERTIME * PAYRATE) + ((hrsWorked - OVERTIME) * overTimeRate);
  } else {
    grossPay = hrsWorked * PAYRATE;
  }

  // Calc taxes and net pay
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
