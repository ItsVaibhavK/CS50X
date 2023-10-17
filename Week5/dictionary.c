// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

#include "dictionary.h"

//Global variables
int wordcount, hvalue;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table

//increased the value of N to 26 to the power 4 to match staff's timing
const unsigned int N = 456976;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    //obtain hash value
    hvalue = hash(word);

    //declare cursor to point to correct index as per hash function
    node *cursor = table[hvalue];

    //iterate through linked list
    while (cursor != NULL)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }

        //remember to move the cursor to the next node
        cursor = cursor->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function

    //hash function using total ASCII of all characters of the string
    //improved the time of this by increasing the value of N above
    int sum = 0;
    int length = strlen(word);

    for (int i = 0; i < length; i++)
    {
        sum += tolower(word[i]);
    }

    return sum % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    //open file, check if there is an error
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("Error.\n");
        return false;
    }

    //buffer to read a string into from the file
    //+1 for \0
    char word[LENGTH + 1];

    //scan file until EOF
    while (fscanf(file, "%s", word) != EOF)
    {
        //create a new node for the word, check for error
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }

        //copy word into node and use the hash function to get a hash value
        strcpy(n->word, word);
        hvalue = hash(word);

        //using hash value, store it into the table
        n->next = table[hvalue];
        table[hvalue] = n;

        //keep a word count to use in size function
        wordcount++;
    }

    //close file
    fclose(file);
    return true;

}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if (wordcount > 0)
    {
        return wordcount;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO

    //iterate through the primary table
    for (int i = 0; i < N; i++)
    {
        //set a cursor to current bucket
        node *cursor = table[i];
        while (cursor != NULL)
        {
            //use a temp node to free
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }

        //freeing the final node
        if (cursor == NULL && i == N - 1)
        {
            free(cursor);
        }
    }

    return true;
}
