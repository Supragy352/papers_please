#ifndef OBJECT_H
#define OBJECT_H

#include <raylib.h>

typedef struct Object
{
    Vector2 position;
    Vector2 size;
    Color color;
} Object;

Object CreateObject(Vector2 position, Vector2 size, Color color) {
    return (Object) {
        .position = position,
        .size = size,
        .color = color
    };
}

void DrawObject(Object object)
{
    DrawRectangleV(object.position, object.size, object.color);
} 

#endif