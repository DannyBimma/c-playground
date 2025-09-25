/*
 * CS50 Recover
 *
 * Recovers JPEGs from a forensic image by scanning 512-byte blocks for JPEG
 * signatures and writing contiguous blocks to sequentially numbered files.
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;
const int BLOCK_SIZE = 512;
int jpeg_count = 0;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: ./recover IMAGE\n");

    return 1;
  }

  // Open forensic image for reading (binary mode)
  FILE *data = fopen(argv[1], "rb");
  if (data == NULL) {
    printf("Unable to open input file\n");

    return 2;
  }

  // Allocate buffer for reading blocks
  BYTE *data_buffer = malloc(BLOCK_SIZE);
  if (data_buffer == NULL) {
    fclose(data);
    printf("Insufficient memory\n");
    return 3;
  }

  FILE *img = NULL;
  char file_name[8]; // e.g., "000.jpg" + NUL

  // Read JPEG blocks into buffer until end of forensic image
  while (fread(data_buffer, sizeof(BYTE), BLOCK_SIZE, data) == BLOCK_SIZE) {
    // Check blocks read to buffer for signature start of new JPEG file
    if (data_buffer[0] == 0xff && data_buffer[1] == 0xd8 &&
        data_buffer[2] == 0xff && (data_buffer[3] & 0xf0) == 0xe0) {
      // if start of new JPEG file and if first JPEG
      if (jpeg_count > 0 && img != NULL) {
        fclose(img);
      }

      sprintf(file_name, "%03i.jpg", jpeg_count);
      img = fopen(file_name, "wb");
      fwrite(data_buffer, sizeof(BYTE), BLOCK_SIZE, img);
      jpeg_count++;
    } else if (jpeg_count > 0) // If no new JPEG header found:
    {
      // continue writing to current JPEG file
      fwrite(data_buffer, sizeof(BYTE), BLOCK_SIZE, img);
    }
  }

  free(data_buffer);
  fclose(data);
  if (img != NULL) {
    fclose(img);
  }

  return 0;
}
