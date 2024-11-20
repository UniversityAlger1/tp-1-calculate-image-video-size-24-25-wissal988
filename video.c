#include "config/video.h"
#include <stdio.h>  // For printf and scanf
#include <string.h>

float video(int w, int h, int durationMovie, int durationCredits, int fps, char* unit) {
    // Constants for pixel sizes
    const int bytesPerPixelColor = 3;  // RGB (24-bit color)
    const int bytesPerPixelBW = 1;    // Black and White (8-bit grayscale)
    const int headerSize = 54;        // Bitmap header size in bytes (per frame)
    
    // Calculate row sizes (aligned to multiples of 4 bytes)
    int rowSizeColor = (w * bytesPerPixelColor + 3) & ~3;
    int rowSizeBW = (w * bytesPerPixelBW + 3) & ~3;
    
    // Calculate frame sizes
    int frameSizeColor = rowSizeColor * h + headerSize;
    int frameSizeBW = rowSizeBW * h + headerSize;
    
    // Calculate total frames
    int totalFramesColor = durationMovie * fps;
    int totalFramesBW = durationCredits * fps;
    
    // Calculate total size in bytes
    long long totalSizeBytes = (long long)totalFramesColor * frameSizeColor +
                               (long long)totalFramesBW * frameSizeBW;
    
    // Convert total size to the desired unit
    if (strcmp(unit, "bt") == 0) {
        // Bytes
        return (float)totalSizeBytes;
    } else if (strcmp(unit, "ko") == 0) {
        // Kilobits (1 Byte = 8 bits, 1 Kilobit = 1024 bits)
        return (float)totalSizeBytes * 8 / 1024;
    } else if (strcmp(unit, "mo") == 0) {
        // Megabits (1 Megabit = 1024 Kilobits)
        return (float)totalSizeBytes * 8 / (1024 * 1024);
    } else if (strcmp(unit, "go") == 0) {
        // Gigabits (1 Gigabit = 1024 Megabits)
        return (float)totalSizeBytes * 8 / (1024 * 1024 * 1024);
    } else {
        // Invalid unit
        printf("Invalid unit. Please use 'bt', 'ko', 'mo', or 'go'.\n");
        return -1;
    }
}

int main() {
    int width, height, durationMovie, durationCredits, fps;
    char unit[3];

    // Input values from the user
    printf("Enter the width of the video: ");
    scanf("%d", &width);
    printf("Enter the height of the video: ");
    scanf("%d", &height);
    printf("Enter the duration of the movie section (in seconds): ");
    scanf("%d", &durationMovie);
    printf("Enter the duration of the credits section (in seconds): ");
    scanf("%d", &durationCredits);
    printf("Enter the frames per second (FPS): ");
    scanf("%d", &fps);
    printf("Enter the unit (bt for bytes, ko for kilobits, mo for megabits, go for gigabits): ");
    scanf("%s", unit);

    // Calculate video size
    float videoSize = video(width, height, durationMovie, durationCredits, fps, unit);
    if (videoSize != -1) {
        printf("The size of the video is: %.2f %s\n", videoSize, unit);
    }

    return 0;
}