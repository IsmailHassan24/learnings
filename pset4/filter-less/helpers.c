#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float blue = image[i][j].rgbtBlue;
            float red = image[i][j].rgbtRed;
            float green = image[i][j].rgbtGreen;
            int average = round((blue + green + red) / 3);
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int SepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int SepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int SepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            if (SepiaBlue < 255)
            {
                image[i][j].rgbtBlue = SepiaBlue;
            }
            else
            {
                image[i][j].rgbtBlue = 255;
            }
            if (SepiaGreen < 255)
            {
                image[i][j].rgbtGreen = SepiaGreen;
            }
            else
            {
                image[i][j].rgbtGreen = 255;
            }
            if (SepiaRed < 255)
            {
                image[i][j].rgbtRed = SepiaRed;
            }
            else
            {
                image[i][j].rgbtRed = 255;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width / 2); j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sum_blue;
            int sum_green;
            int sum_red;
            float counter;
            sum_blue = sum_green = sum_red = counter = 0;
            if (i >= 0 && j >= 0)
            {
                sum_red += temp[i][j].rgbtRed;
                sum_green += temp[i][j].rgbtGreen;
                sum_blue += temp[i][j].rgbtBlue;
                counter++;
            }
            if (i >= 0 && j - 1 >= 0)
            {
                sum_red += temp[i][j - 1].rgbtRed;
                sum_green += temp[i][j - 1].rgbtGreen;
                sum_blue += temp[i][j - 1].rgbtBlue;
                counter++;
            }
            if (i - 1 >= 0 && j >= 0)
            {
                sum_red += temp[i - 1][j].rgbtRed;
                sum_green += temp[i - 1][j].rgbtGreen;
                sum_blue += temp[i - 1][j].rgbtBlue;
                counter++;
            }
            if (i - 1 >= 0 && j - 1 >= 0)
            {
                sum_red += temp[i - 1][j - 1].rgbtRed;
                sum_green += temp[i - 1][j - 1].rgbtGreen;
                sum_blue += temp[i - 1][j - 1].rgbtBlue;
                counter++;
            }
            if ((i >= 0 && j + 1 >= 0) && (i >= 0 && j + 1 < width))
            {
                sum_red += temp[i][j + 1].rgbtRed;
                sum_green += temp[i][j + 1].rgbtGreen;
                sum_blue += temp[i][j + 1].rgbtBlue;
                counter++;
            }
            if ((i - 1 >= 0 && j + 1 >= 0) && (i - 1 >= 0 && j + 1 < width))
            {
                sum_red += temp[i - 1][j + 1].rgbtRed;
                sum_green += temp[i - 1][j + 1].rgbtGreen;
                sum_blue += temp[i - 1][j + 1].rgbtBlue;
                counter++;
            }
            if ((i + 1 >= 0 && j >= 0) && (i + 1 < height && j >= 0))
            {
                sum_red += temp[i + 1][j].rgbtRed;
                sum_green += temp[i + 1][j].rgbtGreen;
                sum_blue += temp[i + 1][j].rgbtBlue;
                counter++;
            }
            if ((i + 1 >= 0 && j - 1 >= 0) && (i + 1 < height && j - 1 >= 0))
            {
                sum_red += temp[i + 1][j - 1].rgbtRed;
                sum_green += temp[i + 1][j - 1].rgbtGreen;
                sum_blue += temp[i + 1][j - 1].rgbtBlue;
                counter++;
            }
            if ((i + 1 >= 0 && j + 1 >= 0) && (i + 1 < height && j + 1 < width))
            {
                sum_red += temp[i + 1][j + 1].rgbtRed;
                sum_green += temp[i + 1][j + 1].rgbtGreen;
                sum_blue += temp[i + 1][j + 1].rgbtBlue;
                counter++;
            }
            image[i][j].rgbtRed = round(sum_red / counter);
            image[i][j].rgbtGreen = round(sum_green / counter);
            image[i][j].rgbtBlue = round(sum_blue / counter);
        }
    }
    return;
}
