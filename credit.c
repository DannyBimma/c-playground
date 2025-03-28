#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if a string contains only digits
int is_digits_only(const char *str) {
    while (*str) {
        if (!isdigit(*str)) {
            return 0;
        }
        str++;
    }
    return 1;
}

// Function to implement Luhn's Algorithm
int luhn_check(const char *number) {
    int len = strlen(number);
    int sum = 0;
    int is_second = 0;
    
    // Start from the rightmost digit
    for (int i = len - 1; i >= 0; i--) {
        int digit = number[i] - '0';
        
        if (is_second) {
            digit *= 2;
            // If product is two digits, add digits separately
            sum += (digit % 10) + (digit / 10);
        } else {
            sum += digit;
        }
        
        is_second = !is_second;
    }
    
    return (sum % 10 == 0);
}

// Function to determine card type
const char* get_card_type(const char *number) {
    int len = strlen(number);
    
    // Check American Express
    if (len == 15 && (strncmp(number, "34", 2) == 0 || strncmp(number, "37", 2) == 0)) {
        return "AMEX";
    }
    
    // Check MasterCard
    if (len == 16 && number[0] == '5' && number[1] >= '1' && number[1] <= '5') {
        return "MASTERCARD";
    }
    
    // Check Visa
    if ((len == 13 || len == 16) && number[0] == '4') {
        return "VISA";
    }
    
    return "INVALID";
}

int main(void) {
    char number[20];
    
    printf("Number: ");
    scanf("%s", number);
    
    // Check if input contains only digits
    if (!is_digits_only(number)) {
        printf("INVALID\n");
        return 0;
    }
    
    // Check if number is valid using Luhn's Algorithm
    if (!luhn_check(number)) {
        printf("INVALID\n");
        return 0;
    }
    
    // Determine and print card type
    printf("%s\n", get_card_type(number));
    
    return 0;
}
