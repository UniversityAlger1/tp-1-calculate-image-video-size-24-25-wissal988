#include "config/coloredBitmap.h"
#include <string.h>
float calculateImageSize(int w, int h, char unit) {
    // Constants
    const int bytesPerPixel = 3; // For RGB (24-bit color)
    const int headerSize = 54;  // Standard Bitmap header size in bytes
    
    // Calculate the size in bytes
    int rowSize = (w * bytesPerPixel + 3) & ~3; // Rows are padded to multiples of 4 bytes
    int imageSize = rowSize * h + headerSize;
    
    // Convert size based on the unit
    switch (unit) {
        case 'B': // Bytes
            return (float)imageSize;
        case 'K': // Kilobytes
            return (float)imageSize / 1024;
        case 'M': // Megabytes
            return (float)imageSize / (1024 * 1024);
        default:
            printf("Invalid unit. Please use 'B', 'K', or 'M'.\n");
            return -1;
    }
}

int main() {
    int width, height;
    char unit;
    
    // Input
    printf("Enter the width of the image: ");
    scanf("%d", &width);
    printf("Enter the height of the image: ");
    scanf("%d", &height);
    printf("Enter the unit (B for Bytes, K for Kilobytes, M for Megabytes): ");
    scanf(" %c", &unit);
    
    // Calculate size
    float size = calculateImageSize(width, height, unit);
    
    if (size != -1) {
        printf("The size of the image is: %.2f %c\n", size, unit);
    }
    
    return 0;
}