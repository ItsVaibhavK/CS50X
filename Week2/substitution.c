#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool valid(string key);
void subst(string plain, string key);

int main(int argc, string argv[])
{
    // check for correct usage
    if (argc != 2)
    {
        printf("Usage: ./substitution *key*\n");
        return 1;
    }

    // check for valid key, perform subsitution
    if (valid(argv[1]))
    {
        string plain = get_string("plaintext: ");
        printf("ciphertext: ");
        subst(plain, argv[1]);
    }
    else
        return 1;
}

// check for valid key
bool valid(string key)
{
    bool length, alpha, unique;
    length = alpha = unique = false;
    int len = strlen(key);

    // check length
    if (len == 26)
        length = true;
    else
        printf("Key must be 26 characters long.\n");

    // check if only alphabets
    for (int i = 0; i < len; i++)
    {
        if (!isalpha(key[i]))
        {
            alpha = false;
            printf("Key must only contain alphabets.\n");
            break;
        }
        else
            alpha = true;
    }

    // check if only unique alphabets
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (toupper(key[i]) != toupper(key[j]))
                unique = true;
            else
            {
                unique = false;
                printf("Key must contain unique characters.\n");
                break;
            }
        }
        if (unique == false)
            break;
    }

    // check if all conditions are satisfied
    if (length == true && alpha == true && unique == true)
        return true;
    else
        return false;
}

void subst(string plain, string key)
{
    int plainlen = strlen(plain);
    int keylen = strlen(key);
    char cipher[plainlen];
    char key_array[keylen];

    for (int i = 0; i < keylen; i++)
    {
        key_array[i] = key[i];
    }

    for (int i = 0; i < plainlen; i++)
    {
        if (isalpha(plain[i]))
        {
            if (islower(plain[i]))
                cipher[i] = key_array[plain[i] - 'a'];
            else if (isupper(plain[i]))
                cipher[i] = key_array[plain[i] - 'A'];
        }
        else
            cipher[i] = plain[i];
    }

    for (int i = 0; i < plainlen; i++)
        printf("%c", cipher[i]);
    printf("\n");
}