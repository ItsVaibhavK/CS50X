// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include<ctype.h>
#include <stdio.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    bool lower, upper, num, sym = false;

    int length = strlen(password);

    //loop through input, set statuses to true if conditions are met
    for (int i = 0; i < length; i++)
    {
        if (islower(password[i]))
        {
            lower = true;
        }

        if(isupper(password[i]))
        {
            upper = true;
        }

        if(isdigit(password[i]))
        {
            num = true;
        }

        if(!isalnum(password[i]))
        {
            sym = true;
        }
    }

    //if all the conditions are satisfied, return true
    if (lower == true && upper == true && num == true && sym == true)
    {
        return true;
    }

    //else return false
    return false;
}
