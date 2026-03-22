#ifndef GAME_H
#define GAME_H

#include "raylib.h"

// TODO: Add your struct definitions here
// Example:
// typedef struct Game {
//     Vector2 player_pos;
//     int score;
// } Game;

// TODO: Add function declarations
void InitGame(int screenWidth, int screenHeight);
void UpdateGame(int screenWidth, int screenHeight);
void DrawGame(void);
void UnloadGame(void);

#endif