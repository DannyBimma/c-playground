#include <stdio.h>
#include <string.h>
#include <cs50.h>

// Function to implement Luhn's Algorithm
bool luhns_algo(long card_num)
{
    int sum = 0;
    bool is_second = false;
    
    // Convert long to string for easier manipulation
    char num_str[20];
    sprintf(num_str, "%ld", card_num);
    int num_len = strlen(num_str);
    
    // Iterate from right to left
    for (int i = num_len - 1; i >= 0; i--)
    {
        int digit = num_str[i] - '0';  // Convert char to int
        
        if (is_second)
        {
            digit *= 2;
            // Add digits separately for two-digit results
            sum += (digit % 10) + (digit / 10);
        }
        else
        {
            sum += digit;
        }
        
        is_second = !is_second;
    }
    
    return (sum % 10 == 0);
}

// Function to determine card type
string card_checker(long num)
{
    // Convert long to string for easier manipulation
    char num_str[20];
    sprintf(num_str, "%ld", num);
    int len = strlen(num_str);
    
    // Check American Express
    if (len == 15 && (strncmp(num_str, "34", 2) == 0 || strncmp(num_str, "37", 2) == 0))
    {
        return "AMEX";
    }
    
    // Check MasterCard
    if (len == 16 && num_str[0] == '5' && num_str[1] >= '1' && num_str[1] <= '5')
    {
        return "MASTERCARD";
    }
    
    // Check Visa
    if ((len == 13 || len == 16) && num_str[0] == '4')
    {
        return "VISA";
    }
    
    return "INVALID";
}

int main(void)
{
    // Get input using CS50's get_long
    long card_num = get_long("Number: ");
    
    // Check if number is valid using Luhn's Algorithm
    if (!luhns_algo(card_num))
    {
        printf("INVALID\n");
        return 0;
    }
    
    // Determine and print card type
    string card_type = card_checker(card_num);
    printf("%s\n", card_type);
    
    return 0;
}
