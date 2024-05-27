#include "helpers.h"
#include <math.h>
#include <string.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //Go through each row
    for(int i = 0; i < height; i++)
    {
        //Go through each column
        for(int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];
            int avg = round((pixel.rgbtBlue + pixel.rgbtRed + pixel.rgbtGreen)/ 3.0);
            image[i][j].rgbtRed = image[i][j].rgbtBlue = image[i][j].rgbtGreen = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //Go through each row
    for(int i = 0; i < height; i++)
    {
        //Go through each column
        for(int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];

            //Apply formula for sepia
            int sepiaRed =   round(.393 * pixel.rgbtRed + .769 * pixel.rgbtGreen + .189 * pixel.rgbtBlue);
            int sepiaGreen = round(.349 * pixel.rgbtRed + .686 * pixel.rgbtGreen + .168 * pixel.rgbtBlue);
            int sepiaBlue =  round(.272 * pixel.rgbtRed + .534 * pixel.rgbtGreen + .131 * pixel.rgbtBlue);

            image[i][j].rgbtRed = sepiaRed > 255 ? 255 : sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen > 255 ? 255 : sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue > 255 ? 255 : sepiaBlue;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    //Transformations to temp
    for(int i = 0; i < height; i++)
    {
        int curpost = 0;
        for(int j = width - 1; j >= 0; j--, curpost++)
        {
            temp[i][curpost] = image[i][j];
        }
    }

    //Copy to final image
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }

    return;
}

// Blur image
