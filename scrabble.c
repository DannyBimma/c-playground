#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

// Scrabble letter values
int letter_val_arr[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main(void)
{
    int player_1_score = 0;
    int player_2_score = 0;

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

    // Calculate score for each word
    for (int i = 0; i < strlen(word_1); i++)
    {
        if (isalpha(word_1[i]))
        {
            player_1_score += letter_val_arr[word_1[i] - 'A'];
        }

        if (isalpha(word_2[i]))
        {
            player_2_score += letter_val_arr[word_2[i] - 'A'];
        }
    } 

    // Print scores
    if (player_1_score > player_2_score)
    {
        printf("Player 1 wins!\n");
    }
    else if (player_2_score > player_1_score)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

    return 0;

}