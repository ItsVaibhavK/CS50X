#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // TODO
    string message = get_string("Message: ");
    int len = strlen(message);

    // Convert each char of input to corresponding ASCII value
    // by using an int array
    int ascii_value[len];
    for (int i = 0; i < len; i++)
    {
        ascii_value[i] = message[i];
    }

    // Using a 2D array to store binary value for each char
    // i = the char, j = its binary value
    // Binary value is being calculated in reverse, so store it in right order to balance that out
    int binary_value[len][BITS_IN_BYTE];
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < BITS_IN_BYTE; j++)
        {
            if (ascii_value[i] > 0)
            {
                if (ascii_value[i] % 2 == 0)
                    binary_value[i][BITS_IN_BYTE - 1 - j] = 0;
                else
                    binary_value[i][BITS_IN_BYTE - 1 - j] = 1;

                ascii_value[i] = ascii_value[i] / 2;
            }
            else
            {
                binary_value[i][BITS_IN_BYTE - 1 - j] = 0;
            }
        }
    }

    // While the binary values were calculated in reverse, print it in regular order
    // The way it was stored took care of the reverse issue
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < BITS_IN_BYTE; j++)
        {
            print_bulb(binary_value[i][j]);
        }
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
