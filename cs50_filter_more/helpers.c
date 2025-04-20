#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = image[i][j].rgbtGreen = image[i][j].rgbtRed = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // 2D Array for original pixel values
    RGBTRIPLE blurred[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Init sums of color values and count
            int blueSum = 0;
            int greenSum = 0;
            int redSum = 0;
            int count = 0;

            // Loop over 3x3 box (offsets) centered on current pixel
            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    // Neighbor pixel
                    int ni = i + di;
                    int nj = j + dj;

                    // Check if neighbor pixel is within bounds
                    if (ni >= 0 && ni < height && nj >= 0 && nj < width)
                    {
                        // Add color values of neighbor pixel to sums
                        blueSum += image[ni][nj].rgbtBlue;
                        greenSum += image[ni][nj].rgbtGreen;
                        redSum += image[ni][nj].rgbtRed;
                        count++;
                    }
                }
            }

            // Calculate average color values for blurred pixel
            blurred[i][j].rgbtBlue = blueSum / count;
            blurred[i][j].rgbtGreen = greenSum / count;
            blurred[i][j].rgbtRed = redSum / count;
        }
    }

    // Copy blurred values back to original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = blurred[i][j];
        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}