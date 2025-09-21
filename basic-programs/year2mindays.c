/*
 * Routine: A program that converts a number of minutes into an exact
 * amount of years and days. A bit stupid, but practice is practice
 * I guess 🤷🏽‍♂️
 * Author: DannyBimma
 * Copyright: (c) 2025 Technomancer Pirate Captain. All Rights Reserved.
 */

#include <limits.h>
#include <math.h>
#include <stdio.h>

int main(void) {
  const long double MINUTES_PER_DAY = 1440.0L;
  const long double DAYS_PER_YEAR_CONT = 365.2425L;    // Gregorian average
  const unsigned long long DAYS_PER_YEAR_INT = 365ULL; // For 365-day years

  long double mins;

  printf("\n");
  printf("---- THE ULTIMATE MINUTE CONVERTER V365.2425 ----\n");
  printf("Enter the number of minutes: ");

  if (scanf("%Lf", &mins) != 1 || mins < 0.0L) {
    fprintf(stderr,
            "Impossible: Please enter a non-negative number 🙂‍↕️\n");

    return 1;
  }

  // Floating-point outputs
  long double days_fp = mins / MINUTES_PER_DAY;
  long double years_fp = days_fp / DAYS_PER_YEAR_CONT;

  // Secondary outputs: for 365-day years and remaining days
  long double days_ld = floorl(days_fp);
  unsigned long long total_days = (unsigned long long)days_ld;
  unsigned long long years_int = total_days / DAYS_PER_YEAR_INT;
  unsigned long long days_int = total_days % DAYS_PER_YEAR_INT;

  printf("\n");
  printf("%.2Lf minutes is approximately:\n", mins);
  printf("%.6Lf years (365.2425 days/year)\n", years_fp);
  printf("%.6Lf days\n", days_fp);
  printf("%llu years and %llu days (exact 365-day years)\n", years_int,
         days_int);
  printf("\n");

  return 0;
}
