/*
 * Author: Technomancer Pirate Captain
 * Routine: Identify the members of Strawhat's flagship
 * Copyright (c) 2025 DannyBimma. All Rights Reserved.
 */

#include <stdio.h>

int main(void) {
  enum mugiwaras {
    Luffy,
    Zoro,
    Nami,
    Usopp,
    Sanji,
    Chopper,
    Robin,
    Franky,
    Brook,
    Jnibe,
    Vivi
  };

  enum mugiwaras captain = Luffy;
  enum mugiwaras navigator = Nami;
  enum mugiwaras chef = Sanji;
  enum mugiwaras sniper = Usopp;

  printf("The Captain was the %dth member of the crew.\n", captain);
  printf("The Navigator was the %dnd member of the crew.\n", navigator);
  printf("The Chef was the %dth member of the crew.\n", chef);
  printf("The Sniper was the %dth member of the crew.\n", sniper);

  return 0;
}
