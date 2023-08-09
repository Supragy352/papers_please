#include <stdio.h>
#include <raylib.h>
#include <stdlib.h>
#include <time.h>

#include "random_gen.h"
#include "object.h"

// Global Contants
int screenHeight = 600;
int screenWidth = 800;
int PAPER_COUNT = 8;

int main() 
{
    srand(time(0));

    InitWindow(screenWidth, screenHeight, "Papers_Please");

    Object PAPERS[PAPER_COUNT];

    for (int i = 0; i < PAPER_COUNT; ++i)
    {
        PAPERS[i] = InitObject(
            RandomVector(100, screenWidth - 100, 100, screenHeight - 100),
            RandomVector(50, 300, 100, 200),
            NewColor(i)
        );
    }

    SetTargetFPS(60);
    ClearBackground(RAYWHITE);
    
    while (!WindowShouldClose()) {
        BeginDrawing();
            for (int i = 0; i < PAPER_COUNT; i++)
            {
                DrawObject(PAPERS[i]);
            }
        EndDrawing();
    }
}