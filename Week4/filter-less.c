#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{

    //use temp to store original values of each pixel
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    //loop through each pixel, new value = average value of that pixel's components
    //values won't end up getting fudged as original values are stored in temp

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = round((temp[i][j].rgbtBlue + temp[i][j].rgbtGreen + temp[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtGreen = round((temp[i][j].rgbtBlue + temp[i][j].rgbtGreen + temp[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtRed = round((temp[i][j].rgbtBlue + temp[i][j].rgbtGreen + temp[i][j].rgbtRed) / 3.0);
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //loop through each pixel

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //for a particular pixel, calculate new INT VALUES of each color
            int red = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int green = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int blue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);


            //Set the values of each color for that one pixel based on the given condition
            if (red > 0xff)
            {
                image[i][j].rgbtRed = 0xff;
            }

            else
            {
                image[i][j].rgbtRed = red;
            }

            if (green > 0xff)
            {
                image[i][j].rgbtGreen = 0xff;
            }

            else
            {
                image[i][j].rgbtGreen = green;
            }

            if (blue > 0xff)
            {
                image[i][j].rgbtBlue = 0xff;
            }

            else
            {
                image[i][j].rgbtBlue = blue;
            }

        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    //temp to store original pixels

    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    //using temp, mirror image

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][width - 1 - j];
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    //use temp to store original pixels to avoid continous blurring

    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    //loops upon loops, baby!
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //initialize the values HERE because they need to reset to zero after each group is totaled up
            int TR = 0, TG = 0, TB = 0;
            double counter = 0;

            for (int k = i - 1; k <= i + 1; k++)
            {
                //boundary check 1
                if (k < 0 || k >= height)
                {
                    continue;
                }

                for (int l = j - 1; l <= j + 1; l++)
                {
                    //boundary check 2
                    if (l < 0 || l >= width)
                    {
                        continue;
                    }


                    TR += temp[k][l].rgbtRed;
                    TG += temp[k][l].rgbtGreen;
                    TB += temp[k][l].rgbtBlue;
                    counter++;
                }
            }
            //assign the new values here before all the variables are reset to zero
            image[i][j].rgbtRed = round(TR / counter);
            image[i][j].rgbtGreen = round(TG / counter);
            image[i][j].rgbtBlue = round(TB / counter);
        }
    }
    return;
}
