#include "object.h"
#include "random.h"
#include <stdlib.h>
#include <time.h>
#include <raylib.h>
#include <stdio.h>

int screenWidth = 800;
int screenHeight = 450;

#define PAPER_COUNT 8

 int main(int argc, char const *argv[]) 
{
    srand(time(0));

    InitWindow(screenWidth, screenHeight, "Game window");

    Object papers[PAPER_COUNT];

    for (int i = 0; i < PAPER_COUNT; i++) {
        papers[i] = CreateObject(
            RandomVector(100, screenWidth - 100, 100, screenHeight - 100), 
            RandomVector(150, 300, 150, 300), 
            NewColor(i));
    };


    while (!WindowShouldClose()) {
        BeginDrawing();
        for (int i = 0; i < PAPER_COUNT; i++) {
            DrawObject(papers[i]);  
        }
        EndDrawing();
    }
    CloseWindow(); // Close window and OpenGL context
    return 0;
}