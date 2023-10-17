#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1

    if (argc != 3)
    {
        printf("Incorrect usage: ./reverse inputfile.wav outputfile.wav\n");
        return 1;
    }

    // Open input file for reading
    // TODO #2

    FILE *input = fopen(argv[1], "r");

    if (input == NULL)
    {
        printf("Could not open input file.\n");
        return 1;
    }

    // Read header
    // TODO #3

    WAVHEADER bufferheader;
    fread(&bufferheader, sizeof(WAVHEADER), 1, input);

    // Use check_format to ensure WAV format
    // TODO #4

    if (check_format(bufferheader) == 0)
    {
        printf("Input is not a WAV file.\n");
        return 1;
    }

    // Open output file for writing
    // TODO #5

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not create output file.\n");
        return 1;
    }

    // Write header to file
    // TODO #6

    fwrite(&bufferheader, sizeof(WAVHEADER), 1, output);

    // Use get_block_size to calculate size of block
    // TODO #7

    int bsize = get_block_size(bufferheader);

    // Write reversed audio to file
    // TODO #8

    //The fseek() or fseeko() function returns 0 if it successfully moves the pointer, a nonzero return value indicates an error
    //if statement can be used as if(fseek(...)) for error crosscheck

    fseek(input, bsize, SEEK_END);
    int buffer[bsize];

    //ftell == current position being pointed to
    // - bsize == the position of yet unread data that will be coming up
    //checking if the position of next group of unread data is inside the header section or not

    while (ftell(input) - bsize > sizeof(bufferheader))
    {
        fseek(input, -2 * bsize, SEEK_CUR);
        fread(buffer, bsize, 1, input);
        fwrite(buffer, bsize, 1, output);
    }


    fclose(input);
    fclose(output);
}

int check_format(WAVHEADER header)
{
    // TODO #4

    BYTE check[] = {"WAVE"};

    for (int i = 0; i < 4; i++)
    {
        if (header.format[i] != check[i])
        {
            return 0;
        }
    }
    return 1;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    //block size = number of channels * bytes per sample

    int bsize = header.numChannels * (header.bitsPerSample / 8);
    return bsize;
}