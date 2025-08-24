#include <math.h>
#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Calculate average using floating-point division and round
            int average = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
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
            float count = 0;

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
            blurred[i][j].rgbtBlue = round(blueSum / count);
            blurred[i][j].rgbtGreen = round(greenSum / count);
            blurred[i][j].rgbtRed = round(redSum / count);
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
    // 2D Array for original pixel values
    RGBTRIPLE temp[height][width];

    // Init Gx and Gy kernels
    int Gx[3][3] = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}};

    int Gy[3][3] = {
        {-1, -2, -1},
        {0, 0, 0},
        {1, 2, 1}};

    // Loop over each pixel in image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Init sums for Gx and Gy for each color channel
            float gxBlue = 0, gyBlue = 0;
            float gxGreen = 0, gyGreen = 0;
            float gxRed = 0, gyRed = 0;

            // Loop over 3x3 box centered on current pixel
            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    // Neighbor pixel
                    int ni = i + di;
                    int nj = j + dj;

                    // Check if neighbor pixel is within bounds
                    // Treat pixels outside bounds as black (0) for calculation
                    if (ni >= 0 && ni < height && nj >= 0 && nj < width)
                    {
                        // Add weighted color values to Gx and Gy sums
                        gxBlue += image[ni][nj].rgbtBlue * Gx[di + 1][dj + 1];
                        gyBlue += image[ni][nj].rgbtBlue * Gy[di + 1][dj + 1];
                        gxGreen += image[ni][nj].rgbtGreen * Gx[di + 1][dj + 1];
                        gyGreen += image[ni][nj].rgbtGreen * Gy[di + 1][dj + 1];
                        gxRed += image[ni][nj].rgbtRed * Gx[di + 1][dj + 1];
                        gyRed += image[ni][nj].rgbtRed * Gy[di + 1][dj + 1];
                    }
                }
            }

            // Calculate final edge value for each color channel
            int finalBlue = round(sqrt(gxBlue * gxBlue + gyBlue * gyBlue));
            int finalGreen = round(sqrt(gxGreen * gxGreen + gyGreen * gyGreen));
            int finalRed = round(sqrt(gxRed * gxRed + gyRed * gyRed));

            // Cap values at 255
            temp[i][j].rgbtBlue = (finalBlue > 255) ? 255 : finalBlue;
            temp[i][j].rgbtGreen = (finalGreen > 255) ? 255 : finalGreen;
            temp[i][j].rgbtRed = (finalRed > 255) ? 255 : finalRed;
        }
    }

    // Copy edges values back to original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }

    return;
}