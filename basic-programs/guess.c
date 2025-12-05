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

int main(void) {
  // Generate random num between 0-420 inclusive
  srand(time(0));

  int min = 0;
  int max = 420;
  int range = (max - min) + 1;

  int random_num = (rand() % range) + min;

  printf("Random number between 0-420 inclusive: %d\n", random_num);
}
