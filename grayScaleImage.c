#include "config/grayScaleImage.h"
float grayScaleImage(int w, int h) {
   // Each pixel in a grayscale image takes 1 byte
   float bytes_per_pixel = 1;

   // Calculate the size of the image in bytes
   float image_size = w * h * bytes_per_pixel;

   // Return the size
   return image_size;
}

int main() {
    int width, height;

    // Input width and height from the user
    printf("Enter the width of the image: ");
    scanf("%d", &width);

    printf("Enter the height of the image: ");
    scanf("%d", &height);

    // Call the function to calculate the size
    float size = grayScaleImage(width, height);

    // Output the result
    printf("The size of the grayscale BMP image is: %.0f bytes\n", size);

    return 0;
}