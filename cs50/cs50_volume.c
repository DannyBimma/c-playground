/*
 * CS50 Volume
 *
 * Scales the volume of a WAV file by a given factor. Reads input WAV, writes
 * output WAV with the same header and samples multiplied by the factor.
 * Usage: ./volume input.wav output.wav factor
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[]) {
  if (argc != 4) {
    printf("Usage: ./volume input.wav output.wav factor\n");

    return 1;
  }

  // Open files and determine scaling factor
  FILE *input = fopen(argv[1], "rb");
  if (input == NULL) {
    printf("Could not open input file.\n");

    return 1;
  }

  FILE *output = fopen(argv[2], "wb");
  if (output == NULL) {
    fclose(input);
    printf("Could not create output file.\n");

    return 1;
  }

  float factor = atof(argv[3]);

  // Copy header from input file to output file
  uint8_t header[HEADER_SIZE];
  fread(header, HEADER_SIZE, 1, input);
  fwrite(header, HEADER_SIZE, 1, output);

  // Read samples from input file and write updated data to output file
  int16_t sample;
  while (fread(&sample, sizeof(int16_t), 1, input) == 1) {
    float scaled = sample * factor;
    if (scaled > 32767.0f)
      scaled = 32767.0f;
    if (scaled < -32768.0f)
      scaled = -32768.0f;
    int16_t out = (int16_t)scaled;
    fwrite(&out, sizeof(int16_t), 1, output);
  }

  fclose(input);
  fclose(output);

  return 0;
}
