#ifndef _RANDOM_H
#define _RANDOM_H

#include <raylib.h>
#include <stdlib.h>

#define  COLOR_COUNT 8

Color colors[] = {
    (Color) {0xe3,0xd1,0x96,0xff},
    (Color) {0xbf,0xb4,0x69,0xff},
    (Color) {219, 188, 140, 0xff},
    (Color) {195, 196, 110,0xff},
    (Color) {207, 164, 145,0xff},
    (Color) {143, 180, 196,0xff},
    (Color) {140, 140, 219,0xff},
    (Color) {141, 201, 155,0xff}
};


int RandomRange(int min, int max) {
    int val = min + (rand() % (max - min + 1));
    return val;
}

Vector2 RandomVector(int minX, int maxX, int minY, int maxY) {
    return (Vector2) {
        RandomRange(minX, maxX),
        // Returns a Random vector with 
        // X = Random between minX and maxX
        RandomRange(minY, maxY)
    };
}

Color NewColor(int index) {
    return colors[index % COLOR_COUNT];
}

#endif