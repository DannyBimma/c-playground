/*
 * CS50 Hello
 *
 * Simple greeting program: prompts for a name and prints "hello, <name>".
 */

#include <cs50.h>
#include <stdio.h>

int main(void) {
  string name = get_string("What's your name? ");
  printf("hello, %s\n", name);
  return 0;
}
