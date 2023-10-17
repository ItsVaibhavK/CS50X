//c = (p + k)%26

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool valid(string s);
string rotate(string plain, int key);

int main(int argc, string argv[])
{
    //no key
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    //invalid key
    else if (!valid(argv[1]))
    {
        printf("Key must be a positive integer\n");
        return 1;
    }

    string plain = get_string("plaintext:  ");
    printf("ciphertext: %s\n", rotate(plain , atoi(argv[1])));
}


//check validity of key
bool valid(string s)
{
    int len = strlen(s);

    for (int i = 0; i < len; i++)
    {
        if (!isdigit(s[i]))
            return false;
    }
    return true;
}


//rotate text with key
string rotate(string plain, int key)
{
    //c and p calculate the relative int values of their ASCII values to 'a' or 'A' depending on case
    char c, p;
    //copies the string-terminating null char
    string cipher = plain;
    int len = strlen(plain);

    for (int i = 0; i < len; i++)
    {
        if (isupper(plain[i]))
        {
            p = plain[i] - 'A';
            c = (p + key) % 26;
            cipher[i] = c + 'A';
        }
        else if (islower(plain[i]))
        {
            p = plain[i] - 'a';
            c = (p + key) % 26;
            cipher[i] = c + 'a';
        }
    }
    return cipher;
}