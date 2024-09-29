#include <stdio.h>

#define WIDTH 10
#define HEIGHT 10

int main() {
    FILE *inputFile = fopen("input.pgm", "rb");
    FILE *outputFile = fopen("output.pgm", "wb");

    if (!inputFile || !outputFile) {
        printf("Error opening files.\n");
        return 1;
    }

    // Read and copy the PGM header
    char header[20];
    fgets(header, sizeof(header), inputFile);
    fputs(header, outputFile);

    fgets(header, sizeof(header), inputFile);
    fputs(header, outputFile);

    fgets(header, sizeof(header), inputFile);
    fputs(header, outputFile);

    // Read image data
    unsigned char image[HEIGHT][WIDTH];
    fread(image, sizeof(unsigned char), WIDTH * HEIGHT, inputFile);

    // Modify one pixel value (e.g., set pixel at (50, 50) to 255)
    image[5][5] = 255;

    // Write modified image data
    fwrite(image, sizeof(unsigned char), WIDTH * HEIGHT, outputFile);

    fclose(inputFile);
    fclose(outputFile);
    return 0;
}