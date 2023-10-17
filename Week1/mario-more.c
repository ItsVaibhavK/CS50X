#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    //prompt user for height
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    //loop for rows
    for (int i = 0; i < height; i++)
    {
        //loop for spaces, spaces == 1 less than height
        for (int a = 0; a < height - i; a++)
        {
            printf(" ");
        }

        //loop for hashes, hashes = same as number of row (1st row == 1 hash, 2nd row == 2 hashes)
        for (int b = 0; b <= i; b++)
        {
            printf("#");
        }

        //fixed space of 2 hashes
        printf("  ");

        //loop for hashes on other side of gap, same as previous loop for hashes
        for (int c = 0; c <= i; c++)
        {
            printf("#");
        }

        //newline to go to next row
        printf("\n");
    }

}