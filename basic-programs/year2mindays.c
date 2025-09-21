/*
 * Routine: A program that converts a number of minutes into an exact
 * amount of years and days. A bit stupid, but practice is practice
 * I guess 🤷🏽‍♂️
 * Author: DannyBimma
 * Copyright: (c) 2025 Technomancer Pirate Captain. All Rights Reserved.
 */

#include <stdio.h>

int main(void) {
  long double mins;
  long double years, days;

  printf("\n");
  printf("---- THE ULTIMATE MINUTE CONVERTER V365.24 ----\n");
  printf("Enter the a of minutes: ");
  scanf("%Lf", &mins);

  years = mins / (365.25 * 24 * 60);
  days = mins / (24 * 60);

  printf("\n");
  printf("%.2Lf minutes is equal to:\n", mins);
  printf("%.6Lf years\n", years);
  printf("%.6Lf days\n", days);
  printf("\n");

  return 0;
}
