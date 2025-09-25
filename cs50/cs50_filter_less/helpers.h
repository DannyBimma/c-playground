/*
 * Prototypes for image processing helpers used by filter.c
 */

#ifndef HELPERS_H
#define HELPERS_H

#include "bmp.h"

// Convert image to grayscale (average of RGB channels)
void grayscale(int height, int width, RGBTRIPLE image[height][width]);

// Convert image to sepia (with channel capping at 255)
void sepia(int height, int width, RGBTRIPLE image[height][width]);

// Reflect image horizontally (mirror across the vertical axis)
void reflect(int height, int width, RGBTRIPLE image[height][width]);

// Apply a 3x3 box blur with edge-aware averaging
void blur(int height, int width, RGBTRIPLE image[height][width]);

#endif // HELPERS_H
