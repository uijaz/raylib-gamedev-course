#include "raylib.h"
#include "game.h"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;
    
    InitWindow(screenWidth, screenHeight, "My Game");
    InitGame(screenWidth, screenHeight);
    
    SetTargetFPS(60);
    
    while (!WindowShouldClose())
    {
        UpdateGame(screenWidth, screenHeight);
        
        BeginDrawing();
        ClearBackground(BLACK);
        DrawGame();
        EndDrawing();
    }
    
    UnloadGame();
    CloseWindow();
    return 0;
}