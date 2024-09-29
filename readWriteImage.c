#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Open the original PPM file for reading
    FILE *image = fopen("car_32x32.ppm", "r");
    if (image == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Read the PPM header
    char format[3];
    int width, height, max_color;
    fscanf(image, "%2s", format);
    fscanf(image, "%d %d", &width, &height);
    fscanf(image, "%d", &max_color);

    // Check if the format is correct
    if (strcmp(format, "P3") != 0) {
        printf("Unsupported PPM format! Only P3 is supported.\n");
        fclose(image);
        return 1;
    }

    // Allocate memory for the image pixels
    int (*pixels)[width][3] = malloc(height * width * 3 * sizeof(int));
    if (pixels == NULL) {
        printf("Memory allocation failed!\n");
        fclose(image);
        return 1;
    }

    // Read the pixel data from the original image
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fscanf(image, "%d %d %d", &pixels[i][j][0], &pixels[i][j][1], &pixels[i][j][2]);
        }
    }

    // Close the original image file
    fclose(image);

    // Change the color of the car body from red to blue and windows to yellow
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // Check if the pixel is red (car body)
            if (pixels[i][j][0] == 255 && pixels[i][j][1] == 0 && pixels[i][j][2] == 0) {
                // Change it to blue
                pixels[i][j][0] = 125;
                pixels[i][j][1] = 64;
                pixels[i][j][2] = 125;
            }
            // Check if the pixel is white (windows)
            if (pixels[i][j][0] == 255 && pixels[i][j][1] == 255 && pixels[i][j][2] == 255) {
                // Change it to yellow
                pixels[i][j][0] = 255;
                pixels[i][j][1] = 255;
                pixels[i][j][2] = 0;
            }
        }
    }

    // Open a new file to write the modified image
    FILE *modified_image = fopen("car_modified_32x32.ppm", "w");
    if (modified_image == NULL) {
        printf("Error creating file!\n");
        free(pixels);
        return 1;
    }

    // Write the PPM header to the new file
    fprintf(modified_image, "P3\n");
    fprintf(modified_image, "%d %d\n", width, height);
    fprintf(modified_image, "%d\n", max_color);

    // Write the modified pixel data to the new file
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fprintf(modified_image, "%d %d %d ", pixels[i][j][0], pixels[i][j][1], pixels[i][j][2]);
        }
        fprintf(modified_image, "\n");
    }

    // Close the modified image file and free allocated memory
    fclose(modified_image);
    free(pixels);

    printf("car_modified_32x32.ppm generated successfully.\n");
    return 0;
}
