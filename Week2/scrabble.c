#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
        return 0;
    }

    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
        return 0;
    }

    else
    {
        printf("Tie!\n");
        return 0;
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    int length = strlen(word);
    int score = 0;

    //points array is points[0] = A, that is points[65 - 65 == 0] as per ASCII
    //since the array is zero indexed, it makes up for the offset in the subtraction value
    //eg - C is 67, 67 - 65 == 2, points[2] = 3 is the 3rd element of the array and so corresponds to C, the 3rd alphabet
    for (int i = 0; i < length; i++)
    {
        if (islower(word[i]))
        {
            score += POINTS[word[i] - 'a'];
        }

        else if (isupper(word[i]))
        {
            score+= POINTS[word[i] - 'A'];
        }
    }

    return score;
}
