#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Function prototypes
int letter_counter(string text);
int word_counter(string text);
int sentence_counter(string text);

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");

    // Count the number of letters, words, and sentences in the text
    int letters = letter_counter(text);
    int words = word_counter(text);
    int sentences = sentence_counter(text);

    // Compute the Coleman-Liau index
    float L = (float)letters / words * 100;
    float S = (float)sentences / words * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // Print the grade level
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int letter_counter(string text)
{
    int letters = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }

    return letters;
}

int word_counter(string text)
{
    int words = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (isspace(text[i]))
        {
            words++;
        }
    }

    return words + 1;
}

int sentence_counter(string text)
{
    int sentences = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }

    return sentences;
}