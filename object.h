#ifndef _OBJECT_H
#define _OBJECT_H

#include <raylib.h>

typedef struct object {
    Vector2 position;
    Vector2 size;
    Color color;
} Object;

Object InitObject(Vector2 _init_pos, Vector2 _init_size, Color _init_color) {
    return (Object) {
        .position = _init_pos,
        .size = _init_size,
        .color = _init_color
    };
}

void DrawObject(Object _drw_obj) {
    DrawRectangleV(_drw_obj.position, _drw_obj.size, _drw_obj.color);
    printf("Drawn Object\n");
}

#endif