/*Copyright (c) 2025 DannyBimma. All Rights Reserved.*/

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int letter_counter(char *text);
int word_counter(char *text);
int sentence_counter(char *text);

int main(void) {
  char text[1000];

  printf("Text: ");
  fgets(text, sizeof(text), stdin);

  // Rmv newline if present
  size_t len = strlen(text);
  if (len > 0 && text[len - 1] == '\n') {
    text[len - 1] = '\0';
  }

  int letters = letter_counter(text);
  int words = word_counter(text);
  int sentences = sentence_counter(text);

  // Coleman-Liau index
  float L = (float)letters / words * 100;
  float S = (float)sentences / words * 100;
  int index = round(0.0588 * L - 0.296 * S - 15.8);

  if (index >= 16) {
    printf("\nThe text has a reading level of grade 16+ 📖\n");
  } else if (index < 1) {
    printf("\nThe text has a reading level of grade 1 📖\n");
  } else {
    printf("\nThe text has a reading level of grade %i 📖\n", index);
  }

  printf("The text contains:\n %i letters.\n %i words.\n %i sentences.\n",
         letters, words, sentences);
}

int letter_counter(char *text) {
  int letters = 0;

  for (int i = 0; i < strlen(text); i++) {
    if (isalpha(text[i])) {
      letters++;
    }
  }

  return letters;
}

int word_counter(char *text) {
  int words = 0;

  for (int i = 0; i < strlen(text); i++) {
    if (isspace(text[i])) {
      words++;
    }
  }

  return words + 1;
}

int sentence_counter(char *text) {
  int sentences = 0;

  for (int i = 0; i < strlen(text); i++) {
    if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
      sentences++;
    }
  }

  return sentences;
}
