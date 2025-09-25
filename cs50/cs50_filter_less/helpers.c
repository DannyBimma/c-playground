#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width]) {
  // Iterate over every row of pixels in the img
  for (int i = 0; i < height; i++) {
    // For each pixel in each row, get average RGB value
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
  // Iterate over each row of pixels in the img
  for (int i = 0; i < height; i++) {
    // For each pixel in each row, calc sepia values based on orginal RGB values
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

      // Cap new sepia RGB values at 255 if exceeded and apply to pixels
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
  // Iterate over each row of pixels in the img
  for (int i = 0; i < height; i++) {
    // For each pixel in each row, rearrange the pixels in reverse order
    for (int j = 0; j < width / 2; j++) {
      RGBTRIPLE temp = image[i][j];

      image[i][j] = image[i][width - j - 1];
      image[i][width - j - 1] = temp;
    }
  }

  return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width]) {
  // Innit 2D array to make copy of img
  RGBTRIPLE image_copy[height][width];

  // Copy orginal img pixel by pixel
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      image_copy[i][j] = image[i][j];
    }
  }

  // Iterate over each row of pixels in the img
  for (int i = 0; i < height; i++) {
    // For each pixel in each row, if at top of img:
    for (int j = 0; j < width; j++) {
      if (i == 0 && j == 0) {
        // set rgb values to average of surrouding pixels
        image[i][j].rgbtRed = round(
            (image_copy[i][j].rgbtRed + image_copy[i][j + 1].rgbtRed +
             image_copy[i + 1][j].rgbtRed + image_copy[i + 1][j + 1].rgbtRed) /
            4.0);

        image[i][j].rgbtGreen =
            round((image_copy[i][j].rgbtGreen + image_copy[i][j + 1].rgbtGreen +
                   image_copy[i + 1][j].rgbtGreen +
                   image_copy[i + 1][j + 1].rgbtGreen) /
                  4.0);

        image[i][j].rgbtBlue =
            round((image_copy[i][j].rgbtBlue + image_copy[i][j + 1].rgbtBlue +
                   image_copy[i + 1][j].rgbtBlue +
                   image_copy[i + 1][j + 1].rgbtBlue)) /
            4.0;
      }
      // If current pixel is within top row, but not at corner:
      else if (i == 0 && j < width - 1) {
        // set rgb values to average of surrouding pixels
        image[i][j].rgbtRed = round(
            (image_copy[i][j].rgbtRed + image_copy[i][j + 1].rgbtRed +
             image_copy[i + 1][j + 1].rgbtRed + image_copy[i + 1][j].rgbtRed +
             image_copy[i + 1][j - 1].rgbtRed + image_copy[i][j - 1].rgbtRed) /
            6.0);

        image[i][j].rgbtGreen =
            round((image_copy[i][j].rgbtGreen + image_copy[i][j + 1].rgbtGreen +
                   image_copy[i + 1][j + 1].rgbtGreen +
                   image_copy[i + 1][j].rgbtGreen +
                   image_copy[i + 1][j - 1].rgbtGreen +
                   image_copy[i][j - 1].rgbtGreen) /
                  6.0);

        image[i][j].rgbtBlue = round(
            (image_copy[i][j].rgbtBlue + image_copy[i][j + 1].rgbtBlue +
             image_copy[i + 1][j + 1].rgbtBlue + image_copy[i + 1][j].rgbtBlue +
             image_copy[i + 1][j - 1].rgbtBlue +
             image_copy[i][j - 1].rgbtBlue) /
            6.0);
      }
      // If current pixel is at top right corner of img:
      else if (i == 0 && j == width - 1) {
        // set rgb values to average of surrouding pixels
        image[i][j].rgbtRed = round(
            (image_copy[i][j].rgbtRed + image_copy[i][j - 1].rgbtRed +
             image_copy[i + 1][j - 1].rgbtRed + image_copy[i + 1][j].rgbtRed) /
            4.0);

        image[i][j].rgbtGreen =
            round((image_copy[i][j].rgbtGreen + image_copy[i][j - 1].rgbtGreen +
                   image_copy[i + 1][j - 1].rgbtGreen +
                   image_copy[i + 1][j].rgbtGreen) /
                  4.0);

        image[i][j].rgbtBlue =
            round((image_copy[i][j].rgbtBlue + image_copy[i][j - 1].rgbtBlue +
                   image_copy[i + 1][j - 1].rgbtBlue +
                   image_copy[i + 1][j].rgbtBlue) /
                  4.0);
      }
      // If current pixel is at leading edge of any inner row:
      else if (i > 0 && i < height - 1 && j == 0) {
        // set rgb values to average of surrouding pixels
        image[i][j].rgbtRed = round(
            (image_copy[i][j].rgbtRed + image_copy[i - 1][j].rgbtRed +
             image_copy[i - 1][j + 1].rgbtRed + image_copy[i][j + 1].rgbtRed +
             image_copy[i + 1][j + 1].rgbtRed + image_copy[i + 1][j].rgbtRed) /
            6.0);

        image[i][j].rgbtGreen =
            round((image_copy[i][j].rgbtGreen + image_copy[i - 1][j].rgbtGreen +
                   image_copy[i - 1][j + 1].rgbtGreen +
                   image_copy[i][j + 1].rgbtGreen +
                   image_copy[i + 1][j + 1].rgbtGreen +
                   image_copy[i + 1][j].rgbtGreen) /
                  6.0);

        image[i][j].rgbtBlue = round(
            (image_copy[i][j].rgbtBlue + image_copy[i - 1][j].rgbtBlue +
             image_copy[i - 1][j + 1].rgbtBlue + image_copy[i][j + 1].rgbtBlue +
             image_copy[i + 1][j + 1].rgbtBlue +
             image_copy[i + 1][j].rgbtBlue) /
            6.0);
      }
      // If current pixel is at trailing edge of any inner row:
      else if (i > 0 && i < height - 1 && j == width - 1) {
        // set rgb values to average of surrouding pixels
        image[i][j].rgbtRed = round(
            (image_copy[i][j].rgbtRed + image_copy[i - 1][j].rgbtRed +
             image_copy[i - 1][j - 1].rgbtRed + image_copy[i][j - 1].rgbtRed +
             image_copy[i + 1][j - 1].rgbtRed + image_copy[i + 1][j].rgbtRed) /
            6.0);

        image[i][j].rgbtGreen =
            round((image_copy[i][j].rgbtGreen + image_copy[i - 1][j].rgbtGreen +
                   image_copy[i - 1][j - 1].rgbtGreen +
                   image_copy[i][j - 1].rgbtGreen +
                   image_copy[i + 1][j - 1].rgbtGreen +
                   image_copy[i + 1][j].rgbtGreen) /
                  6.0);

        image[i][j].rgbtBlue = round(
            (image_copy[i][j].rgbtBlue + image_copy[i - 1][j].rgbtBlue +
             image_copy[i - 1][j - 1].rgbtBlue + image_copy[i][j - 1].rgbtBlue +
             image_copy[i + 1][j - 1].rgbtBlue +
             image_copy[i + 1][j].rgbtBlue) /
            6.0);
      }
      // If current pixel is at bottom left corner of img:
      else if (i == height - 1 && j == 0) {
        // set rgb values to average of surrouding pixels
        image[i][j].rgbtRed = round(
            (image_copy[i][j].rgbtRed + image_copy[i][j + 1].rgbtRed +
             image_copy[i - 1][j + 1].rgbtRed + image_copy[i - 1][j].rgbtRed) /
            4.0);

        image[i][j].rgbtGreen =
            round((image_copy[i][j].rgbtGreen + image_copy[i][j + 1].rgbtGreen +
                   image_copy[i - 1][j + 1].rgbtGreen +
                   image_copy[i - 1][j].rgbtGreen) /
                  4.0);

        image[i][j].rgbtBlue =
            round((image_copy[i][j].rgbtBlue + image_copy[i][j + 1].rgbtBlue +
                   image_copy[i - 1][j + 1].rgbtBlue +
                   image_copy[i - 1][j].rgbtBlue) /
                  4.0);
      }
      // If current pixel is within bottom row, but not at corner:
      else if (i == height - 1 && j < width - 1) {
        // set rgb values to average of surrouding pixels
        image[i][j].rgbtRed = round(
            (image_copy[i][j].rgbtRed + image_copy[i][j + 1].rgbtRed +
             image_copy[i - 1][j + 1].rgbtRed + image_copy[i - 1][j].rgbtRed +
             image_copy[i - 1][j - 1].rgbtRed + image_copy[i][j - 1].rgbtRed) /
            6.0);

        image[i][j].rgbtGreen =
            round((image_copy[i][j].rgbtGreen + image_copy[i][j + 1].rgbtGreen +
                   image_copy[i - 1][j + 1].rgbtGreen +
                   image_copy[i - 1][j].rgbtGreen +
                   image_copy[i - 1][j - 1].rgbtGreen +
                   image_copy[i][j - 1].rgbtGreen) /
                  6.0);

        image[i][j].rgbtBlue = round(
            (image_copy[i][j].rgbtBlue + image_copy[i][j + 1].rgbtBlue +
             image_copy[i - 1][j + 1].rgbtBlue + image_copy[i - 1][j].rgbtBlue +
             image_copy[i - 1][j - 1].rgbtBlue +
             image_copy[i][j - 1].rgbtBlue) /
            6.0);
      }
      // If current pixel is at bottom right corner of img:
      else if (i == height - 1 && j == width - 1) {
        // set rgb values to average of surrouding pixels
        image[i][j].rgbtRed = round(
            (image_copy[i][j].rgbtRed + image_copy[i][j - 1].rgbtRed +
             image_copy[i - 1][j - 1].rgbtRed + image_copy[i - 1][j].rgbtRed) /
            4.0);

        image[i][j].rgbtGreen =
            round((image_copy[i][j].rgbtGreen + image_copy[i][j - 1].rgbtGreen +
                   image_copy[i - 1][j - 1].rgbtGreen +
                   image_copy[i - 1][j].rgbtGreen) /
                  4.0);

        image[i][j].rgbtBlue =
            round((image_copy[i][j].rgbtBlue + image_copy[i][j - 1].rgbtBlue +
                   image_copy[i - 1][j - 1].rgbtBlue +
                   image_copy[i - 1][j].rgbtBlue) /
                  4.0);
      }
      // If current pixel is NOT at any edges or corners
      else {
        // set rgb values to average of surrouding pixels
        image[i][j].rgbtRed = round(
            (image_copy[i][j].rgbtRed + image_copy[i][j - 1].rgbtRed +
             image_copy[i - 1][j - 1].rgbtRed + image_copy[i - 1][j].rgbtRed +
             image_copy[i - 1][j + 1].rgbtRed + image_copy[i][j + 1].rgbtRed +
             image_copy[i + 1][j + 1].rgbtRed + image_copy[i + 1][j].rgbtRed +
             image_copy[i + 1][j - 1].rgbtRed) /
            9.0);

        image[i][j].rgbtGreen =
            round((image_copy[i][j].rgbtGreen + image_copy[i][j - 1].rgbtGreen +
                   image_copy[i - 1][j - 1].rgbtGreen +
                   image_copy[i - 1][j].rgbtGreen +
                   image_copy[i - 1][j + 1].rgbtGreen +
                   image_copy[i][j + 1].rgbtGreen +
                   image_copy[i + 1][j + 1].rgbtGreen +
                   image_copy[i + 1][j].rgbtGreen +
                   image_copy[i + 1][j - 1].rgbtGreen) /
                  9.0);

        image[i][j].rgbtBlue = round(
            (image_copy[i][j].rgbtBlue + image_copy[i][j - 1].rgbtBlue +
             image_copy[i - 1][j - 1].rgbtBlue + image_copy[i - 1][j].rgbtBlue +
             image_copy[i - 1][j + 1].rgbtBlue + image_copy[i][j + 1].rgbtBlue +
             image_copy[i + 1][j + 1].rgbtBlue + image_copy[i + 1][j].rgbtBlue +
             image_copy[i + 1][j - 1].rgbtBlue) /
            9.0);
      }
    }
  }

  return;
}
