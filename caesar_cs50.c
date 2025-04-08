#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

bool digits(string arg);
char rotate(char p, int k);

int main(int argc, string argv[])
{
    // only run program if user inputs a single valid command-line argument
    if (argc != 2 || !digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // convert input arg to an int cipher key
    int k = atoi(argv[1]);

    // prompt user for plaintext input
    string plaintext = get_string("plaintext:  ");

    // print ciphertext label
    printf("ciphertext: ");

    // rotate and print each char in plaintext by cihper key positions
    for (int i = 0, l = strlen(plaintext); i < l; i++)
    {
        printf("%c", rotate(plaintext[i], k));
    }

    printf("\n");
    return 0;
}

// create function to check if input arg is all digits
bool digits(string arg)
{
    bool str_stat;

    // loop over the string & check if each char is a digit
    for (int i = 0, l = strlen(arg); i < l; i++)
    {
        if (isdigit(arg[i]))
        {
            str_stat = true;
        }
        else
        {
            str_stat = false;
        }
    }

    return str_stat;
}

// create function to increase an input char by an input int places in ASCII
// function should wrap around in an alphabetical index
char rotate(char p, int k)
{
    char c;

    if (isupper(p))
    {
        c = (p - 'A' + k) % 26;
        return c + 'A';
    }
    else if (islower(p))
    {
        c = (p - 'a' + k) % 26;
        return c + 'a';
    }
    else
    {
        c = p;
    }

    return c;
}