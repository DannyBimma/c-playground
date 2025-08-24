#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // print the winner
    if (score1 > score2)
    {
        printf("Player 1 Wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 Wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

// calculate the value of each word
int compute_score(string word)
{
    // initialise array of values
    int val[strlen(word)];
    // initialise adder for sum of values at 0
    int sum = 0;

    // loop over each char in the word
    for (int i = 0; i < strlen(word); i++)
    {
        // assign the points value to each char in word
        switch (toupper(word[i]))
        {
            case 'A':
                val[i] = POINTS[0];
                break;

            case 'B':
                val[i] = POINTS[1];
                break;

            case 'C':
                val[i] = POINTS[2];
                break;

            case 'D':
                val[i] = POINTS[3];
                break;

            case 'E':
                val[i] = POINTS[4];
                break;

            case 'F':
                val[i] = POINTS[5];
                break;

            case 'G':
                val[i] = POINTS[6];
                break;

            case 'H':
                val[i] = POINTS[7];
                break;

            case 'I':
                val[i] = POINTS[8];
                break;

            case 'J':
                val[i] = POINTS[9];
                break;

            case 'K':
                val[i] = POINTS[10];
                break;

            case 'L':
                val[i] = POINTS[11];
                break;

            case 'M':
                val[i] = POINTS[12];
                break;

            case 'N':
                val[i] = POINTS[13];
                break;

            case 'O':
                val[i] = POINTS[14];
                break;

            case 'P':
                val[i] = POINTS[15];
                break;

            case 'Q':
                val[i] = POINTS[16];
                break;

            case 'R':
                val[i] = POINTS[17];
                break;

            case 'S':
                val[i] = POINTS[18];
                break;

            case 'T':
                val[i] = POINTS[19];
                break;

            case 'U':
                val[i] = POINTS[20];
                break;

            case 'V':
                val[i] = POINTS[21];
                break;

            case 'W':
                val[i] = POINTS[22];
                break;

            case 'X':
                val[i] = POINTS[23];
                break;

            case 'Y':
                val[i] = POINTS[24];
                break;

            case 'Z':
                val[i] = POINTS[25];
                break;

            default:
                val[i] = 0;
        }
    }

    // find the sum of all values in value array
    for (int i = 0; i < strlen(word); i++)
    {
        sum = sum + val[i];
    }

    return sum;
}