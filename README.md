# Projects-cs4023
Requirements:
The image file should be in PGM (Portable Graymap Format), which is simple to handle.
Assume the image has a fixed size of 100x100 for simplicity.

Explanation:

File Handling:

The program opens an 8-bit grayscale image (input.pgm) and writes the modified version to (output.pgm).
PGM Header Handling:

The PGM file format has a simple header (e.g., "P5\nWIDTH HEIGHT\nMAX_VALUE\n"). This code copies the header from the input file to the output file.
Image Data Handling:

It reads the 100x100 pixel image data into a 2D array (image).
Modifies a pixel at position (5, 5) to 255 (white).

File Output:
The modified data is written to output.pgm.