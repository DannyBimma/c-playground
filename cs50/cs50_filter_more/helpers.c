/*
 * Image processing helpers for CS50 Filters (more):
 * - grayscale: convert each pixel to its luminance average
 * - reflect: mirror image horizontally in-place
 * - blur: box blur using a 3x3 kernel with edge-aware averaging
 * - edges: Sobel edge detection with per-channel clamping
 */

#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width]) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      // Calculate average using floating-point division and round
      int average = round(
          (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) /
          3.0);
      image[i][j].rgbtBlue = average;
      image[i][j].rgbtGreen = average;
      image[i][j].rgbtRed = average;
    }
  }

  return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width]) {
  for (int i = 0; i < height; i++) {
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
  // Destination buffer for blurred values; read from source image only
  RGBTRIPLE blurred[height][width];

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      // Accumulate neighbour colour sums and count valid samples
      int sumB = 0, sumG = 0, sumR = 0;
      int count = 0;

      // Loop over 3x3 box (offsets) centred on current pixel
      for (int di = -1; di <= 1; di++) {
        for (int dj = -1; dj <= 1; dj++) {
          // Neighbour pixel
          int ni = i + di;
          int nj = j + dj;

          // Check if neighbour pixel is within bounds
          if (ni >= 0 && ni < height && nj >= 0 && nj < width) {
            sumB += image[ni][nj].rgbtBlue;
            sumG += image[ni][nj].rgbtGreen;
            sumR += image[ni][nj].rgbtRed;
            count++;
          }
        }
      }

      // Calculate average colour values for blurred pixel
      blurred[i][j].rgbtBlue = (BYTE)round((double)sumB / count);
      blurred[i][j].rgbtGreen = (BYTE)round((double)sumG / count);
      blurred[i][j].rgbtRed = (BYTE)round((double)sumR / count);
    }
  }

  // Copy blurred values back to original image
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      image[i][j] = blurred[i][j];
    }
  }

  return;
}

// Detect edges (Sobel operator)
void edges(int height, int width, RGBTRIPLE image[height][width]) {
  // Temporary buffer for edge-detected values
  RGBTRIPLE temp[height][width];

  // Sobel Gx and Gy kernels
  int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
  int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

  // Loop over each pixel in image
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      // Accumulate Gx and Gy for each channel using integer math
      int gxBlue = 0, gyBlue = 0;
      int gxGreen = 0, gyGreen = 0;
      int gxRed = 0, gyRed = 0;

      // Loop over 3x3 box centred on current pixel
      for (int di = -1; di <= 1; di++) {
        for (int dj = -1; dj <= 1; dj++) {
          // Neighbor pixel
          int ni = i + di;
          int nj = j + dj;

          // Check bounds; treat out-of-bounds as black (implicit zeros)
          if (ni >= 0 && ni < height && nj >= 0 && nj < width) {
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

      // Calculate final edge value for each colour channel
      int finalBlue =
          (int)round(sqrt((double)(gxBlue * gxBlue + gyBlue * gyBlue)));
      int finalGreen =
          (int)round(sqrt((double)(gxGreen * gxGreen + gyGreen * gyGreen)));
      int finalRed = (int)round(sqrt((double)(gxRed * gxRed + gyRed * gyRed)));

      // Clamp to 0..255 and store
      temp[i][j].rgbtBlue = (finalBlue > 255) ? 255 : finalBlue;
      temp[i][j].rgbtGreen = (finalGreen > 255) ? 255 : finalGreen;
      temp[i][j].rgbtRed = (finalRed > 255) ? 255 : finalRed;
    }
  }

  // Copy edge-detected values back to original image
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      image[i][j] = temp[i][j];
    }
  }

  return;
}
