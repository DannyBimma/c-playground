/*
 * Image processing helpers for CS50 Filter (less):
 * - grayscale: convert each pixel to its luminance average
 * - sepia: apply sepia tone with channel capping
 * - reflect: mirror image horizontally in-place
 * - blur: box blur using a 3x3 kernel with edge-aware averaging
 */

#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width]) {
  // Iterate over every pixel and set each channel to the average
  for (int i = 0; i < height; i++) {
    // For each pixel in the row, compute average RGB value
    for (int j = 0; j < width; j++) {
      int avg = round(
          (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) /
          3.0);

      // Set all RGB values to the average
      image[i][j].rgbtRed = avg;
      image[i][j].rgbtGreen = avg;
      image[i][j].rgbtBlue = avg;
    }
  }

  return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width]) {
  // Iterate over each pixel and compute sepia-transformed channels
  for (int i = 0; i < height; i++) {
    // For each pixel, calculate sepia values based on original RGB values
    for (int j = 0; j < width; j++) {
      int sepiaRed = round((0.393 * image[i][j].rgbtRed) +
                           (0.769 * image[i][j].rgbtGreen) +
                           (0.189 * image[i][j].rgbtBlue));
      int sepiaGreen = round((0.349 * image[i][j].rgbtRed) +
                             (0.686 * image[i][j].rgbtGreen) +
                             (0.168 * image[i][j].rgbtBlue));
      int sepiaBlue = round((0.272 * image[i][j].rgbtRed) +
                            (0.534 * image[i][j].rgbtGreen) +
                            (0.131 * image[i][j].rgbtBlue));

      // Cap sepia channel values at 255 and apply
      if (sepiaRed > 255) {
        image[i][j].rgbtRed = 255;
      } else {
        image[i][j].rgbtRed = sepiaRed;
      }

      if (sepiaGreen > 255) {
        image[i][j].rgbtGreen = 255;
      } else {
        image[i][j].rgbtGreen = sepiaGreen;
      }

      if (sepiaBlue > 255) {
        image[i][j].rgbtBlue = 255;
      } else {
        image[i][j].rgbtBlue = sepiaBlue;
      }
    }
  }

  return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width]) {
  // Swap pixels symmetrically across the vertical midline
  for (int i = 0; i < height; i++) {
    // For each pixel in the row, up to the midpoint
    for (int j = 0; j < width / 2; j++) {
      RGBTRIPLE temp = image[i][j];

      image[i][j] = image[i][width - j - 1];
      image[i][width - j - 1] = temp;
    }
  }

  return;
}

// Blur image (3x3 box blur with edge handling)
void blur(int height, int width, RGBTRIPLE image[height][width]) {
  // Make a copy to ensure reads are from the original state
  RGBTRIPLE src[height][width];
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      src[i][j] = image[i][j];
    }
  }

  // For each pixel, average all valid neighbors in the 3x3 window
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      int sumR = 0, sumG = 0, sumB = 0;
      int count = 0;

      for (int di = -1; di <= 1; di++) {
        int ni = i + di;
        if (ni < 0 || ni >= height)
          continue;
        for (int dj = -1; dj <= 1; dj++) {
          int nj = j + dj;
          if (nj < 0 || nj >= width)
            continue;
          sumR += src[ni][nj].rgbtRed;
          sumG += src[ni][nj].rgbtGreen;
          sumB += src[ni][nj].rgbtBlue;
          count++;
        }
      }

      image[i][j].rgbtRed = (BYTE)round((double)sumR / count);
      image[i][j].rgbtGreen = (BYTE)round((double)sumG / count);
      image[i][j].rgbtBlue = (BYTE)round((double)sumB / count);
    }
  }

  return;
}
