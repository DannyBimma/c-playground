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
    string text = get_string("Text: ");

    int letters = letter_counter(text);
    int words = word_counter(text);
    int sentences = sentence_counter(text);

    // Compute the Coleman-Liau index
    float L = (float)letters / words * 100;
    float S = (float)sentences / words * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index >= 16)
    {
        printf("\nThe above text has a reading level of grade 16+ 📖\n");
    }
    else if (index < 1)
    {
        printf("\nThe above text has a reading level of grade 1 📖\n");
    }
    else
    {
        printf("\nThe above text has a reading level of grade %i 📖\n", index);
    }

    printf("The text contains:\n %i letters.\n %i words.\n %i sentences.\n", letters, words, sentences);
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