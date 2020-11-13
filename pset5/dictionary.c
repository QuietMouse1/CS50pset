// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include "dictionary.h"

int dictionary_size = 0 ;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    // check if the word is longer than one and smaller than 45
    int hash_index = hash(word);
    char copied_word[45];
    strcpy(copied_word, word);

    if (strlen(word) > 1 && strlen(word) < 45)
    {
        // check for apostrophes, john's
        if (word[(strlen(word) - 2)] == 39)
        {
            memcpy(copied_word, word, (strlen(word) - 2));
        }
        // check for apostrophes, johns'
        else if (word[(strlen(word) - 1)] == 39)
        {
            memcpy(copied_word, word, (strlen(word) - 1));
        }
        for (node *tmp = table[hash_index] ; tmp != NULL; tmp = tmp->next)
        {
            //check for lower case
            if (strcasecmp(tmp->word, copied_word) == 0)
            {
                return true;
            }
        }
    }
    else
    {
        return true;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    // Lets use the first letter of the word to return the index.
    char lower_case = tolower(word[0]);
    int index = lower_case - 97;
    return index;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO

    char word[LENGTH];
    node *list = NULL;

    // Open dictonary file
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        printf("Invalid file \n");
        return false;
    }

    // Read strings from file one at a time
    while (fscanf(dict, "%s", word) != EOF)
    {
        // Create a new node for each word.
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        strcpy(n->word, word);
        n->next = NULL;

        // Hash word to obtain hash value
        int index = hash(word);

        // Insert node into hash table at that location
        if (table[index] == NULL)
        {
            table[index] = n;
            dictionary_size++;
        }
        else
        {
            list = table[index];
            n->next = table[index]->next;
            table[index]->next = n;
            dictionary_size++;
        }
    }
    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return dictionary_size;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    /*
    // some table might be empty!!!
    for (int i = 0; i < N; i++)
    {
        for (node *tmp = table[i] ; tmp != NULL; tmp = tmp->next)
        {
            free(tmp);
        }
    }
    for (int i = 0; i < N; i++)
    {
        free(table[i]);
    }
    */
    for (int i = 0; i < N; i ++)
    {
        node *head = table[i];
        node *cursor = head;
        node *tmp = head;
        while (cursor != NULL)
        {
            cursor = cursor->next;
            free(tmp);
            tmp = cursor;
        }
    }
    return true;
}
