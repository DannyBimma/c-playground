#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool validate_key(string key);
string encrypt_text(string plaintext, string key);

int main(int argc, string argv[])
{
    // Command-line argument check
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Get and validate key
    string key = argv[1];

    if (!validate_key(key))
    {
        printf("Invalid: Please run program by providing a 26 alphabetical character key.\n");
        return 1;
    }

    // Get plaintext, encrypt, and print ciphertext
    string plaintext = get_string("plaintext:  ");

    string ciphertext = encrypt_text(plaintext, key);

    printf("ciphertext: %s\n", ciphertext);

    return 0;
}

bool validate_key(string key)
{
    int n = strlen(key);

    // Check how long that thang is 😉
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
            return false; // Not an alphabetic char
        }
        int index = toupper(key[i]) - 'A';
        if (freq[index] > 0)
        {
            return false; // Duplicate char found
        }

        freq[index]++;
    }

    return true;
}

string encrypt_text(string plaintext, string key)
{
    int n = strlen(plaintext);
    string ciphertext = plaintext;

    for (int i = 0; i < n; i++)
    {
        if (isalpha(plaintext[i]))
        {
            // Preserve case
            bool is_upper = isupper(plaintext[i]);
            int index = toupper(plaintext[i]) - 'A'; // 0-based index

            // Substitute chars using key and maintain case
            char substituted_char = key[index];
            ciphertext[i] = is_upper ? toupper(substituted_char) : tolower(substituted_char);
        }
        else
        {
            // Keep non-alphabetic characters unchanged
            ciphertext[i] = plaintext[i];
        }
    }

    return ciphertext;
}