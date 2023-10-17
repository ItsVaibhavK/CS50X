//AMEX == 15, start with 34 or 37
//MASTERCARD == 16, start with 51, 52, 53, 54, 55
//VISA == 13 & 16, start with 4
//INVALID even if it doesn't match any of these, like a phone number

//Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
//Add the sum to the sum of the digits that weren’t multiplied by 2.
//If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!


#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //get card number from user
    long card = get_long("Number: ");

    //calculate the number of digits in the card
    //store card number in temp to avoid changing actual card number
    //start counter at 1 to compensate for (number/10 > 0) giving 1 less than actual count
    long temp1 = card;
    int counter = 1;
    while (temp1 / 10 > 0)
    {
        temp1 = temp1 / 10;
        counter++;
    }

    //check for invalid number of digits in card number
    if (counter < 13 || counter == 14 || counter > 16)
    {
        printf("INVALID\n");
        //REMEMBER TO EXIT FROM THE PROGRAM
        return 0;
    }

    //Luhn's algorithm for checking if card number is mathematicalaly valid
    int sum1 = 0;
    int sum2 = 0;
    long temp2 = card;
    int total = 0;
    int digit1, digit2;
    int d1, d2;

    do
    {
        //First, we deal with last digit and store in digit1
        digit1 = temp2 % 10;
        //update the value of temp2 to remove last digit from it so we can later access next last digit
        temp2 /= 10;
        //add up all the digits according to algorithm that are related to the actual last digit of card number
        sum1 += digit1;


        //Now, deal with second last digit of original number, store in digit2
        digit2 = temp2 % 10;
        //update the value of temp2 to access next digit later above
        temp2 /= 10;

        //double second last digit
        digit2 *= 2;
        //have to add individual digits in this sequence, not just the products directly so have to split the product again
        //eg if digit2 = 12, in sum2 we have to add 1+2 not something + 12
        d1 = digit2 % 10;
        d2 = digit2 / 10;
        sum2 = sum2 + d1 + d2;
    }
    while (temp2 > 0);
    total = sum1 + sum2;


    //now check the algo
    if (total % 10 != 0)
    {
        printf("INVALID\n");
        //REMEMBER TO EXIT FROM THE PROGRAM
        return 0;
    }


    //get the first 2 digits of the card
    long check = card;
    do
    {
        check = check / 10;
    }
    while (check > 100);


    //check if card number is AMEX
    if ((check / 10 == 3 && check % 10 == 4) || (check / 10 == 3 && check % 10 == 7))
    {
        printf("AMEX\n");
    }
    //check if card number is MASTERCARD
    else if (check / 10 == 5 && 0 < (check % 10) && (check % 10) < 6)
    {
        printf("MASTERCARD\n");
    }
    //check if card number is VISA
    else if (check / 10 == 4)
    {
        printf("VISA\n");
    }
    //invalid for any other number that has reached this far
    else
    {
        printf("INVALID\n");
    }
}