#include <stdio.h>
#include <raylib.h>
#include <stdlib.h>
#include <time.h>
#include <raymath.h>

#include "random.h"
#include "object.h"

// Global Contants
int screenHeight = 600;
int screenWidth = 800;

int PAPER_COUNT = 8;

int draggeObjectIndex = -1;
Vector2 mOffset = {0,0};

int main() 
{
    srand(time(0));

    InitWindow(screenWidth, screenHeight, "Papers_Please");

    Object PAPERS[PAPER_COUNT];

    for (int i = 0; i < PAPER_COUNT; i++)
    {
        PAPERS[i] = InitObject(
            RandomVector(100, screenWidth/2, 100, screenHeight/2),
            RandomVector(150, screenWidth/2, 150, screenHeight/2),
            NewColor(i)
        );
        printf("--%d--\n", i);
    }

    SetTargetFPS(90);
    ClearBackground(RAYWHITE);
    
    while (!WindowShouldClose()) {
        // Update

        Vector2 mPos = GetMousePosition();

        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            for (int i = 0; i < PAPER_COUNT; ++i)
            {
                Object obj = PAPERS[i];

                Rectangle objR = {
                    obj.position.x,
                    obj.position.y,
                    obj.size.x,
                    obj.size.y
                };

                if (CheckCollisionPointRec(mPos, objR))
                {
                    draggeObjectIndex = i;
                    mOffset = Vector2Subtract(obj.position, mPos);
                    break;
                }
            }
        }

        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
        {
            draggeObjectIndex = -1;
        }

        if (draggeObjectIndex != -1)
        {
            //printf("%d",draggeObjectIndex);
            PAPERS[draggeObjectIndex].position = Vector2Add(mPos, mOffset);
        }
        // Update
        
        BeginDrawing();
            for (int i = PAPER_COUNT - 1; i > -1; i--)
            {
                DrawObject(PAPERS[i]);
            }
        EndDrawing();

        ClearBackground(RAYWHITE);
    }
}