/*
 * Routine: An interactive program that greets the user by name
 * and asks a deep philosophical question with different responses
 * based on their answer.
 * Author: DannyBimma
 * Copyright: (c) 2025 Technomancer Pirate Captain. All Rights Reserved.
 */

#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main() {
  char name[50];
  char res[4]; // buffer for yes/no response

  // Get and format initial user input
  printf("Enter your name: ");

  fgets(name, sizeof(name), stdin);
  name[strcspn(name, "\n")] = '\0'; // remove trailing newline from fgets

  printf("Hello, %s!\n", name);

  // Ask the philosophical question and process response
  printf("Do you believe? \n");

  fgets(res, sizeof(res), stdin);
  res[strcspn(res, "\n")] = '\0';

  // Convert response to lowercase for case-insensitive comparison
  for (int i = 0; res[i]; i++)
    res[i] = tolower(res[i]);

  // Provide response based on user's answer
  if (strcmp(res, "yes") == 0 || strcmp(res, "y") == 0) {
    printf("Welcome to the Matrix, %s. We've been expecting you 😎 !!\n", name);
  } else if (strcmp(res, "no") == 0 || strcmp(res, "n") == 0) {
    printf("You are not ready, %s. You remain blind. Sad to see 😔 !!\n", name);
  } else {
    printf("Invalid Response !!\n"); // only accepts yes/no or y/n

    return 1;
  }

  return 0;
}
