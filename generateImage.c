#include <stdio.h>

int main() {
    // Open the PPM file for writing
    FILE *image = fopen("car_32x32.ppm", "w");
    if (image == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Write the PPM header
    fprintf(image, "P3\n");
    fprintf(image, "32 32\n");
    fprintf(image, "255\n");

    // Define colors (R, G, B)
    int black[] = {0, 0, 0};         // Black (wheels, outline)
    int white[] = {255, 255, 255};    // White (windows)
    int red[] = {255, 0, 0};          // Red (car body)
    int blue[] = {0, 0, 255};         // Blue (background sky)
    int gray[] = {128, 128, 128};     // Gray (road)
    int green[] = {0, 128, 0};        // Green (grass)

    // Define the pixel data for the 32x32 image
    int pixels[32][32][3];

    // Initialize all pixels as blue (background sky)
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 32; j++) {
            pixels[i][j][0] = blue[0];
            pixels[i][j][1] = blue[1];
            pixels[i][j][2] = blue[2];
        }
    }

    // Draw the road (bottom part of the image)
    for (int i = 24; i < 32; i++) {
        for (int j = 0; j < 32; j++) {
            pixels[i][j][0] = gray[0];
            pixels[i][j][1] = gray[1];
            pixels[i][j][2] = gray[2];
        }
    }

    // Draw the grass (above the road)
    for (int i = 20; i < 24; i++) {
        for (int j = 0; j < 32; j++) {
            pixels[i][j][0] = green[0];
            pixels[i][j][1] = green[1];
            pixels[i][j][2] = green[2];
        }
    }

    // Draw the car body (red rectangle)
    for (int i = 12; i < 20; i++) {
        for (int j = 6; j < 26; j++) {
            pixels[i][j][0] = red[0];
            pixels[i][j][1] = red[1];
            pixels[i][j][2] = red[2];
        }
    }

    // Draw the car windows (white rectangles)
    for (int i = 13; i < 17; i++) {
        for (int j = 10; j < 14; j++) {
            pixels[i][j][0] = white[0];
            pixels[i][j][1] = white[1];
            pixels[i][j][2] = white[2];
        }
    }
    for (int i = 13; i < 17; i++) {
        for (int j = 18; j < 22; j++) {
            pixels[i][j][0] = white[0];
            pixels[i][j][1] = white[1];
            pixels[i][j][2] = white[2];
        }
    }

    // Draw the wheels (black circles)
    for (int i = 18; i < 22; i++) {
        for (int j = 8; j < 12; j++) {
            pixels[i][j][0] = black[0];
            pixels[i][j][1] = black[1];
            pixels[i][j][2] = black[2];
        }
    }
    for (int i = 18; i < 22; i++) {
        for (int j = 20; j < 24; j++) {
            pixels[i][j][0] = black[0];
            pixels[i][j][1] = black[1];
            pixels[i][j][2] = black[2];
        }
    }

    // Write pixel data to the PPM file
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 32; j++) {
            fprintf(image, "%d %d %d ", pixels[i][j][0], pixels[i][j][1], pixels[i][j][2]);
        }
        fprintf(image, "\n");
    }

    // Close the file
    fclose(image);

    printf("car_32x32.ppm generated successfully.\n");
    return 0;
}
