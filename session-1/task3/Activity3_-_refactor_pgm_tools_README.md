# Activity 4: PGM Image Tools with Structures

## Learning Objectives

After completing this activity, you should be able to:
- Apply structures to complex real-world applications
- Use structures to encapsulate related data
- Design functions that operate on structure parameters
- Manage memory for structures with dynamic arrays
- Refactor existing code to improve its organisation and maintainability

## Background

PGM (Portable Gray Map) is a simple image format that stores grayscale images in a plain text format. The PGM format includes:
- A magic number "P2" indicating the file type
- Width and height dimensions
- Maximum gray value (typically 255)
- A grid of pixel values representing the image

The current implementation of the PGM image tools passes separate parameters for width, height, and pixel arrays. This approach becomes unwieldy as the number of parameters grows. Using a structure to encapsulate all the image data will greatly improve code organisation and readability.

## Setting Up Your Environment

In GitHub Codespaces, you may find it helpful to install a PGM viewer extension to visualise your images:

1. Click on the Extensions icon in the sidebar (or press Ctrl+Shift+X)
2. Search for "PBM Viewer" (this supports PBM, PGM, and PPM formats)
3. Install the extension
4. After installation, you can right-click on any .pgm file and select "Open with PBM Viewer"

This will allow you to see the actual images instead of just the raw text data, making it easier to verify your implementations work correctly.

## The Task

Your task is to refactor the previous `pgm_tools.c` file by:

1. Defining a `PGMImage` structure to encapsulate:
   - Width and height
   - Maximum gray value
   - 2D array of pixel values

2. Refactoring the following functions to use the `PGMImage` structure:
   - `readPGMImage()`
   - `invertImage()`
   - `rotateImage()`
   - `savePGMImage()`

3. Testing your implementation with the previous PGM files

## Hints and Tips

1. **Structure Definition**: Start by defining the PGMImage structure:
   ```c
   typedef struct {
       int width;
       int height;
       int maxGray;
       unsigned char **pixels;  /* 2D array of pixel values */
   } PGMImage;
   ```

2. **Memory Management**: You'll need to allocate memory for the pixel array:
   ```c
   /* Allocate memory for the image structure */
   PGMImage *image = (PGMImage *)malloc(sizeof(PGMImage));
   
   /* Allocate memory for the rows */
   image->pixels = (unsigned char **)malloc(height * sizeof(unsigned char *));
   
   /* Allocate memory for each row */
   for (int i = 0; i < height; i++) {
       image->pixels[i] = (unsigned char *)malloc(width * sizeof(unsigned char));
   }
   ```

3. **Freeing Memory**: Don't forget to free all allocated memory:
   ```c
   void freePGMImage(PGMImage *image) {
       if (image == NULL) return;
       
       /* Free each row */
       for (int i = 0; i < image->height; i++) {
           free(image->pixels[i]);
       }
       
       /* Free the array of rows */
       free(image->pixels);
       
       /* Free the image structure itself */
       free(image);
   }
   ```

4. **Function Signatures**: Refactor the function signatures to use the structure:

   Original:
   ```c
   unsigned char **readPGMImage(const char *filename, int *width, int *height, int *maxGray);
   ```
   
   Refactored:
   ```c
   PGMImage *readPGMImage(const char *filename);
   ```

5. **Error Handling**: Make sure to handle memory allocation errors and file I/O errors properly:
   ```c
   if (image == NULL) {
       fprintf(stderr, "Error: Memory allocation failed\n");
       return NULL;
   }
   ```

## The Benefits of Refactoring

After refactoring, observe the following improvements:
- Clearer function signatures (fewer parameters)
- More coherent data representation (image properties kept together)
- Better readability (code expresses the problem domain more clearly)
- Easier maintenance (changes to image representation only need to be made in one place)
- Better error handling (can return NULL for the entire structure instead of managing errors for separate components)

## Expected Functionality

Your refactored code should maintain the same functionality:
1. Reading PGM images from files
2. Displaying image information and data
3. Inverting the colours of an image (maxGray - value)
4. Rotating an image (90°, 180°, or 270°)
5. Saving modified images to new PGM files

## Testing Your Implementation

Test your implementation with the previous sample images.

Try each operation and verify that the output files match those produced by the original implementation.


## Extension Challenges

If you finish early, consider these extensions:

1. Add a function to resize the image (scale up or down)
2. Implement a function to apply a blur filter to the image
3. Add the ability to crop a section of the image
4. Implement an edge detection algorithm
