#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;
int BLOCK_SIZE = 512;
int jpeg_count = 0;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // Open forensic image for reading
    FILE *data = fopen(argv[1], "r");
    if (argv[1] == NULL)
    {
        printf("Unable to read files\n");
        return 2;
    }

    // Allocate memory on heap to read data into & write from
    BYTE *data_buffer = malloc(BLOCK_SIZE);

    FILE *img = NULL;
    char file_name[sizeof(char) * 8];

    // Read JPEG blocks into buffer until end of forensic image
    while (fread(data_buffer, sizeof(BYTE), BLOCK_SIZE, data) == BLOCK_SIZE)
    {
        // Check blocks read to buffer for signature start of new JPEG file
        if (data_buffer[0] == 0xff && data_buffer[1] == 0xd8 && data_buffer[2] == 0xff && (data_buffer[3] & 0xf0) == 0xe0)
        {
            // if start of new JPEG file and if first JPEG
            if (jpeg_count == 0)
            {
                sprintf(file_name, "%03i.jpg", jpeg_count);

                img = fopen(file_name, "w");

                fwrite(data_buffer, sizeof(BYTE), BLOCK_SIZE, img);

                jpeg_count++;
            }
            else
            {
                fclose(img);

                sprintf(file_name, "%03i.jpg", jpeg_count);

                img = fopen(file_name, "w");

                fwrite(data_buffer, sizeof(BYTE), BLOCK_SIZE, img);

                jpeg_count++;
            }
        }
        else if (jpeg_count > 0) // If no new JPEG header found:
        {
            // continue writing to current JPEG file
            fwrite(data_buffer, sizeof(BYTE), BLOCK_SIZE, img);
        }
    }

    free(data_buffer);
    fclose(data);
    fclose(img);

    return 0;
}