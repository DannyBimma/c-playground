#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

// Letter values
int const A = 1;
int const B = 3;
int const C = 3;
int const D = 2;
int const E = 1;
int const F = 4;
int const G = 2;
int const H = 4;
int const I = 1;
int const J = 8;
int const K = 5;
int const L = 1;
int const M = 3;
int const N = 1;
int const O = 1;
int const P = 3;
int const Q = 10;
int const R = 1;
int const S = 1;
int const T = 1;
int const U = 1;
int const V = 4;
int const W = 4;
int const X = 8;
int const Y = 4;
int const Z = 10;

int main(void)
{
    int score = 0;

    // Get user input
    string word_1 = get_string("Player 1: ");
    string word_2 = get_string("Player 2: ");

    // Convert to uppercase
    for (int i = 0; i < strlen(word_1); i++)
    {
        word_1[i] = toupper(word_1[i]);
    }
    for (int i = 0; i < strlen(word_2); i++)
    {
        word_2[i] = toupper(word_2[i]);
    }

    

}