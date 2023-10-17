#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

int main(void)
{
    int height;

    //prompt for height between 1 and 8
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    //rows loop, number of rows == height from user
    for (int i = 0; i < height; i++)
    {
        //spaces loop per row, number of spaces == 1 less than height
        for (int j = 0; j < height - i; j++)
        {
            printf(" ");
        }

        //hashes loop, number of hashes == the number of the row it is on (1st row == 1 hash, 2nd row == 2 hashes, etc.)
        for(int k = 0; k <= i; k++)
        {
            printf("#");
        }
    printf("\n");
    }
}