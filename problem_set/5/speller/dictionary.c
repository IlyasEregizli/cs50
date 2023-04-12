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
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 1000000;

// Hash table
node *table[N];

int wordcount = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int hashNum = hash(word);
    // cursor variable
    node *cursor = table[hashNum];
    // loop until end of list
    while (cursor != NULL)
    {
        //check if same
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        // else, move cursor along
        cursor = cursor->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    long sum = 0;

    for (int i = 0; i < strlen(word); i++)
    {
        sum += tolower(word[i]);
    }
    return sum % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open dicitonary
    FILE *DictFile = fopen(dictionary, "r");

    // chec if return value is NULL
    if (DictFile == NULL)
    {
        return false;
    }

    // read strings from file
    char str[LENGTH + 1];
    while (fscanf(DictFile, "%s", str) != EOF)
    {
        //create node for each word
        node *temporary = malloc(sizeof(node));

        if (temporary == NULL)
        {
            return false;
        }
        strcpy(temporary->word, str);

        // employ hash funciton
        int hashNum = hash(str);

        //check if linked list is empty
        temporary->next = table[hashNum];
        table[hashNum] = temporary;
        wordcount++;
    }
    // close file
    fclose(DictFile);
    return true;

}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return wordcount;
}



// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *n = table[i];

        node *temp = n;

        while (n != NULL)
        {
            n = n-> next;

            free(temp);

            temp = n;
        }
    }
    return true;
}
