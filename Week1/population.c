#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int a, b, n;
    do
    {
        a = get_int("Starting population: ");
    }
    while (a < 9);

    // TODO: Prompt for end size
    do
    {
        b = get_int("Ending population: ");
    }
    while (b < a);

    // TODO: Calculate number of years until we reach threshold
    for (n = 0; a <  b; n++)
    {
        a = a + (a / 3) - (a / 4);
    }

    // TODO: Print number of years
    printf("Years: %i\n", n);
}
