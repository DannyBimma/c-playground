/*
 * Routine: A classic 'Guess the Number' game! The goal is to guess the
 * correct number (0-420) that the game's code will randomly generate.
 *
 * Author: DannyBimma
 *
 * Copyright: (c) 2025 Technomancer Pirate Captain. All Rights Reserved.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Prototypes
int user_guess();
int guess_checker(int guess, int target, int attempts_left);

int main(void) {
  // Generate random num between 0-420 inclusive
  srand(time(0));

  int min = 0;
  int max = 420;
  int range = (max - min) + 1;

  int random_num = (rand() % range) + min;

  int max_attempts = 10;
  int attempts_used = 0;
  int game_won = 0;

  // Game loop
  while (attempts_used < max_attempts && !game_won) {
    int guess = user_guess();
    attempts_used++;
    int attempts_left = max_attempts - attempts_used;

    if (guess_checker(guess, random_num, attempts_left)) {
      game_won = 1;
      printf("\n");
      printf("*** CONGRATULATIONS! ***\n");
      printf("You guessed the correct number: %d\n", random_num);
      printf("It took you %d attempt(s) to win!\n", attempts_used);
      printf("*** YOU ARE A GUESSING CHAMPION! ***\n");
    }
  }

  // Game over message if player didn't win
  if (!game_won) {
    printf("\n");
    printf("Game Over! You've run out of attempts.\n");
    printf("The correct number was: %d\n", random_num);
    printf("Better luck next time!\n");
  }

  return 0;
}

// Ask the user for their guess
int user_guess(void) {
  int guess;
  int valid_input = 0;

  printf("\n");
  printf("--GUESS THE NUMBER: ULTIMATE EDITION--\n");

  while (!valid_input) {
    printf("Try to guess the correct number between 0-420!!\n");
    printf("Enter your guess: ");

    if (scanf("%d", &guess) == 1) {
      // Clear any remaining characters in input buffer
      while (getchar() != '\n')
        ;
      valid_input = 1;
    } else {
      // Clear invalid input from buffer
      while (getchar() != '\n')
        ;
      printf("Invalid input! Please enter a valid number.\n\n");
    }
  }

  return guess;
}

// Check the user's guess and provide feedback
int guess_checker(int guess, int target, int attempts_left) {
  if (guess == target) {
    return 1; // Correct guess
  } else if (guess < target) {
    printf("Too low! ");
    printf("Attempts remaining: %d\n", attempts_left);
    return 0;
  } else {
    printf("Too high! ");
    printf("Attempts remaining: %d\n", attempts_left);
    return 0;
  }
}
