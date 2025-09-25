/*
 * CS50 Scrabble
 *
 * Computes Scrabble-like scores for two input words and prints the winner or
 * a tie. Letter scores are based on the classic English Scrabble distribution.
 */

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Function prototypes
int score_calc(string word);
void to_uppercase(string word);

// Scrabble letter values
int letter_val_arr[26] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                          1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main(void) {
  int player_1_score = 0;
  int player_2_score = 0;

  // Get user input
  string word_1 = get_string("Player 1: ");
  string word_2 = get_string("Player 2: ");

  // Convert to uppercase
  to_uppercase(word_1);
  to_uppercase(word_2);

  // Calculate score for each word
  player_1_score = score_calc(word_1);
  player_2_score = score_calc(word_2);

  // Print scores
  if (player_1_score > player_2_score) {
    printf("Player 1 wins!\n");
  } else if (player_2_score > player_1_score) {
    printf("Player 2 wins!\n");
  } else {
    printf("Tie!\n");
  }

  return 0;
}

// Score calc function
int score_calc(string word) {
  int score = 0;
  int length = strlen(word);

  for (int i = 0; i < length; i++) {
    if (isalpha(word[i])) {
      score += letter_val_arr[word[i] - 'A'];
    }
  }

  return score;
}

// Uppercase function
void to_uppercase(string word) {
  int length = strlen(word);

  for (int i = 0; i < length; i++) {
    word[i] = toupper(word[i]);
  }
}
