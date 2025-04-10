#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

bool digits(string arg);
char rotate(char p, int k);

int main(int argc, string argv[])
{
    // Input validation
    if (argc != 2 || !digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Convert input arg to int
    int k = atoi(argv[1]);

    string plaintext = get_string("plaintext:  ");

    // Label
    printf("ciphertext: ");

    // Rotate and print each char in plaintext using key
    for (int i = 0, l = strlen(plaintext); i < l; i++)
    {
        printf("%c", rotate(plaintext[i], k));
    }

    printf("\n");
    return 0;
}

// Check if input arg is all digits
bool digits(string arg)
{
    for (int i = 0, l = strlen(arg); i < l; i++)
    {
        if (!isdigit(arg[i]))
        {
            return false;
        }
    }

    return true;
}

// Rotate and wrap chars by key
char rotate(char p, int k)
{
    if (isupper(p))
    {
        // Rotate uppercase letter and return
        return ((p - 'A' + k) % 26) + 'A';
    }
    else if (islower(p))
    {
        // Rotate lowercase letter and return
        return ((p - 'a' + k) % 26) + 'a';
    }
    else
    {
        return p;
    }
}