/*
 * CS50 Credit
 *
 * Validates a credit card number using Luhn's algorithm and prints the
 * issuer (AMEX, MASTERCARD, VISA) or INVALID.
 */

#include <cs50.h>
#include <stdio.h>
#include <string.h>

bool luhns_algo(long card_num);
string card_checker(long num);

int main(void) {
  long card_num = get_long("Number: ");

  // Validation
  if (!luhns_algo(card_num)) {
    printf("INVALID\n");

    return 0;
  }

  // Result
  string card_type = card_checker(card_num);
  printf("%s\n", card_type);

  return 0;
}

// Luhn's Algorithm
bool luhns_algo(long card_num) {
  int sum = 0;
  bool flag = false;

  // Cast long to string for digit-wise processing
  char num_str[20];
  sprintf(num_str, "%ld", card_num);
  int num_len = strlen(num_str);

  // Iterate starting from end
  for (int i = num_len - 1; i >= 0; i--) {
    // Convert char to int
    int digit = num_str[i] - '0';

    if (flag) {
      digit *= 2;
      // Add digits separately for two digit results
      sum += (digit % 10) + (digit / 10);
    } else {
      sum += digit;
    }

    // Flip flag
    flag = !flag;
  }

  return (sum % 10 == 0);
}

string card_checker(long num) {
  // Cast long to string
  char num_str[20];
  sprintf(num_str, "%ld", num);
  int len = strlen(num_str);

  if (len == 15 &&
      (strncmp(num_str, "34", 2) == 0 || strncmp(num_str, "37", 2) == 0)) {
    return "AMEX";
  }

  if (len == 16 && num_str[0] == '5' && num_str[1] >= '1' &&
      num_str[1] <= '5') {
    return "MASTERCARD";
  }

  if ((len == 13 || len == 16) && num_str[0] == '4') {
    return "VISA";
  }

  return "INVALID";
}
