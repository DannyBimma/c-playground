// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Arbitrarily large number of buckets, cause bigger is better
const unsigned int N = 65536;

// Hash table
node *table[N];

// Global variable to store word count
unsigned int word_count = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Hash word to get hash value
    unsigned int index = hash(word);

    // Access linked list at that index in hash table
    node *cursor = table[index];

    // Loop over list to find the word (case-insensitive)
    while (cursor != NULL)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // Hash function
    unsigned long hash_value = 5381;
    int c;

    while ((c = *word++))
    {
        // To lowercase for hashing consistency (dictionary words are lowercase)
        hash_value = ((hash_value << 5) + hash_value) + tolower(c);
    }

    return hash_value % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open dictionary file
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", dictionary);
        return false;
    }

    // Buffer for reading words
    char word_buffer[LENGTH + 1];

    // Read words from file one by one
    while (fscanf(file, "%s", word_buffer) == 1)
    {
        // Create a new node
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            fclose(file);
            fprintf(stderr, "Memory allocation failed.\n");
            return false; // Failure due to memory allocation
        }

        // Copy word into node
        strcpy(new_node->word, word_buffer);
        new_node->next = NULL;

        // Hash word to get index
        unsigned int index = hash(word_buffer);

        // Insert node into hash table at index (prepend)
        new_node->next = table[index];
        table[index] = new_node;

        word_count++;
    }

    // Check for errors after loop
    if (ferror(file))
    {
        fclose(file);
        fprintf(stderr, "Error reading from dictionary %s.\n", dictionary);
        return false;
    }

    // Close dictionary file
    fclose(file);

    // Indicate success
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // Loop over each bucket in hash table
    for (unsigned int i = 0; i < N; i++)
    {
        // Pointer and tmp pointer to traverse the linked list
        node *cursor = table[i];
        node *tmp;

        // Free nodes in the current list
        while (cursor != NULL)
        {
            tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
        // Mark the table entry as NULL after freeing
        table[i] = NULL;
    }
    // Reset word count
    word_count = 0;
    return true;
}