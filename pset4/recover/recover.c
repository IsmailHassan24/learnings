#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }
    char *input_file = argv[1];
    FILE *inptr = fopen(input_file, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", input_file);
        return 2;
    }
    BYTE buffer[512];
    int count = 0;
    FILE *image_pointer = NULL;
    char filename[8];
    while (fread(&buffer, 512, 1, inptr) == 1)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (!(count == 0))
            {
                fclose(image_pointer);
            }
            sprintf(filename, "%03i.jpg", count);
            image_pointer = fopen(filename, "w");
            count++;
        }
        if (!(count == 0))
        {
            fwrite(&buffer, 512, 1, image_pointer);
        }
    }
    fclose(inptr);
    fclose(image_pointer);
    return 0;
}
