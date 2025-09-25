/*
 * Prototypes for image processing helpers used by filters.c
 */

#ifndef HELPERS_H
#define HELPERS_H

#include "bmp.h"

// Convert image to grayscale (average of RGB channels)
void grayscale(int height, int width, RGBTRIPLE image[height][width]);

// Reflect image horizontally (mirror across the vertical axis)
void reflect(int height, int width, RGBTRIPLE image[height][width]);

// Detect edges using Sobel operator with clamping to 255
void edges(int height, int width, RGBTRIPLE image[height][width]);

// Apply a 3x3 box blur with edge-aware averaging
void blur(int height, int width, RGBTRIPLE image[height][width]);

#endif // HELPERS_H
