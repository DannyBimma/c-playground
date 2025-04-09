#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool validate_key(string key);
char *encrypt_text(string plaintext, string key);

int main(int argc, string argv[])
{
    // Command-line argument check
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];

    // Validate the key
    if (!validate_key(key))
    {
        printf("Invalid: Please run program by providing a 26 alphabetical character key.\n");
        return 1;
    }

    string plaintext = get_string("plaintext:  ");

    // Encrypt the plaintext
    char *ciphertext = encrypt_text(plaintext, key);

    // Print the ciphertext
    printf("ciphertext: %s\n", ciphertext);

    // Free allocated memory for ciphertext
    free(ciphertext);

    return 0;
}

// Function to validate the key
bool validate_key(string key)
{
    int n = strlen(key);

    // Check if the key length is 26
    if (n != 26)
    {
        return false;
    }

    // Check if all characters are alphabetic and unique
    int freq[26] = {0}; // Frequency array for letters A-Z
    for (int i = 0; i < n; i++)
    {
        if (!isalpha(key[i]))
        {
            return false; // Not an alphabetic character
        }
        int index = toupper(key[i]) - 'A';
        if (freq[index] > 0)
        {
            return false; // Duplicate character found
        }
        freq[index]++;
    }

    return true; // Key is valid
}

// Function to encrypt the text using the substitution key
char *encrypt_text(string plaintext, string key)
{
    int n = strlen(plaintext);
    // Allocate memory for the ciphertext (+1 for the null terminator)
    char *ciphertext = malloc((n + 1) * sizeof(char));
    if (ciphertext == NULL)
    {
        // Handle memory allocation failure if necessary
        fprintf(stderr, "Memory allocation failed\n");
        exit(1); // Exit if memory cannot be allocated
    }

    for (int i = 0; i < n; i++)
    {
        if (isalpha(plaintext[i]))
        {
            // Preserve case
            bool is_upper = isupper(plaintext[i]);
            int index = toupper(plaintext[i]) - 'A'; // Get 0-based index (A=0, B=1, ...)

            // Get the substituted character from the key
            char substituted_char = key[index];

            // Apply original case
            ciphertext[i] = is_upper ? toupper(substituted_char) : tolower(substituted_char);
        }
        else
        {
            // Keep non-alphabetic characters unchanged
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[n] = '\0'; // Null-terminate the ciphertext string

    return ciphertext;
}
