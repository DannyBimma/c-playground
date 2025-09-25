/*
 * CS50 Filter (less)
 *
 * A command-line BMP image filter that applies one of four effects to a
 * 24-bit uncompressed BMP 4.0 image and writes the result to a new file.
 *
 * Supported filters (flags):
 *   -b  box blur
 *   -g  grayscale
 *   -r  horizontal reflection (mirror)
 *   -s  sepia tone
 *
 * Usage: ./filter -[bgrs] infile.bmp outfile.bmp
 */

#include "helpers.h"
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  // Valid single-letter filter options (used with a leading '-')
  const char *filters = "bgrs";

  // Get filter flag and check validity
  char filter = getopt(argc, argv, filters);
  if (filter == '?' || filter == -1) {
    printf("Invalid or missing filter.\n");

    return 1;
  }

  // Ensure only one filter
  if (getopt(argc, argv, filters) != -1) {
    printf("Only one filter allowed.\n");

    return 2;
  }

  // Ensure proper usage
  if (argc != optind + 2) {
    printf("Usage: ./filter [flag] infile outfile\n");

    return 3;
  }

  // Store filenames (remaining args after getopt processing)
  char *infile = argv[optind];
  char *outfile = argv[optind + 1];

  // Open input BMP (binary mode)
  FILE *inptr = fopen(infile, "rb");
  if (inptr == NULL) {
    printf("Could not open %s.\n", infile);

    return 4;
  }

  // Open output BMP (binary mode)
  FILE *outptr = fopen(outfile, "wb");
  if (outptr == NULL) {
    fclose(inptr);
    printf("Could not create %s.\n", outfile);

    return 5;
  }

  // Read infile's BITMAPFILEHEADER
  BITMAPFILEHEADER bf;
  fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

  // Read infile's BITMAPINFOHEADER
  BITMAPINFOHEADER bi;
  fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

  // Ensure infile is (likely) a 24-bit uncompressed BMP 4.0
  if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
      bi.biBitCount != 24 || bi.biCompression != 0) {
    fclose(outptr);
    fclose(inptr);
    printf("Unsupported file format.\n");

    return 6;
  }

  // Get image dimensions
  int height = abs(bi.biHeight);
  int width = bi.biWidth;

  // Allocate memory for image (height x width 2D array)
  RGBTRIPLE(*image)[width] = calloc(height, width * sizeof(RGBTRIPLE));
  if (image == NULL) {
    printf("Not enough memory to store image.\n");
    fclose(outptr);
    fclose(inptr);

    return 7;
  }

  // Determine padding for scanlines
  int padding = (4 - (width * sizeof(RGBTRIPLE)) % 4) % 4;

  // Read all scanlines into memory
  for (int i = 0; i < height; i++) {
    // Read one row of pixels
    fread(image[i], sizeof(RGBTRIPLE), width, inptr);

    // Skip over input padding
    fseek(inptr, padding, SEEK_CUR);
  }

  // Filter image
  switch (filter) {
  // Blur
  case 'b':
    blur(height, width, image);
    break;

  // Grayscale
  case 'g':
    grayscale(height, width, image);
    break;

  // Reflection
  case 'r':
    reflect(height, width, image);
    break;

  // Sepia
  case 's':
    sepia(height, width, image);
    break;
  }

  // Write outfile's BITMAPFILEHEADER
  fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

  // Write outfile's BITMAPINFOHEADER
  fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

  // Write pixel data to outfile
  for (int i = 0; i < height; i++) {
    // Write one row of pixels
    fwrite(image[i], sizeof(RGBTRIPLE), width, outptr);

    // Write padding bytes at end of row
    for (int k = 0; k < padding; k++) {
      fputc(0x00, outptr);
    }
  }

  // Free memory for image
  free(image);

  // Close files
  fclose(inptr);
  fclose(outptr);

  return 0;
}
