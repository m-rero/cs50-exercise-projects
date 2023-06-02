// Implements a dictionary's functionality
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>


#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 100000000;

// Hash table
node *table[N];

//declare variables
unsigned int word_count = 0;
unsigned int hash_value;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    hash_value = hash(word);
    node *cursor = table[hash_value];

    while (cursor != NULL)
    {
        if (strcmp(cursor->word, word) == 0)
        {
            return true;
        }
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
     unsigned long total = 0;
     for (int i = 0; i < strlen(word); i++)
     {
         total += tolower(word[i]);
     }


    return total % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO

    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    // Read strings from file one at a time
    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF)
    {
        // Allocate a new node for the word
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            return false;
        }
        strcpy(new_node->word, word);
        new_node->next = NULL;

        // Get the index for the word in the hash table
        unsigned int index = hash(word);

        // Insert the new node at the beginning of the linked list
        new_node->next = table[index];
        table[index] = new_node;
    }

    // Close dictionary
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    if (&load) // If dictionary has been loaded successfully
    {
        return word_count;
    }
    else
    {
        return 0;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        // Traverse linked list at index i
        node *cursor = table[i];
        while (cursor != NULL)
        {
            // Keep track of next node to free
            node *temp = cursor->next;

            // Free current node
            free(cursor);

            // Move cursor to next node
            cursor = temp;
        }

        // Set pointer at index i to NULL
        table[i] = NULL;
    }



    return true;
}
