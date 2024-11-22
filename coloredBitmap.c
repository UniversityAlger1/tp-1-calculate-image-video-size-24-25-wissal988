#include <string.h>
#include "config/coloredBitmap.h"
// Parameters:
//   w: width of the image
//   h: height of the image
//   u: Unit of the output value. It could be 'bt' bits, 'ko' kilobits, 'mo' megabits, 'go' gigabits
// Return value
//   colored image size Bitmap (based on the unit passed parametter)
float coloredBitmap(int w, int h, char* unit) {
   // YOUR CODE HERE - BEGIN
// Taille de base en bits (3 octets par pixel)
    float colorsize = w * h * 3 ;

    // Conversion en fonction de l'unité
    if (strcmp(unit, "bt") == 0) {
        return colorsize*8; // Taille en bits
    } else if (strcmp(unit, "ko") == 0) {
        return colorsize / 1024; // Taille en kilobits
    } else if (strcmp(unit, "mo") == 0) {
        return (colorsize /1024) / 1024; // Taille en mégabits
    } else if (strcmp(unit, "go") == 0) {
        return ((colorsize /1024) / 1024) / 1024; // Taille en gigabits
    }else 
    return colorsize;
   // YOUR CODE HERE - END
   return 0;
}
