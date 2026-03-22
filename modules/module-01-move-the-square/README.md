# Module 1 — Move the Square

*A gentle introduction to C, raylib, and the game loop.*

---

## 🎯 Learning Outcomes

By the end of this module you will be able to:

- Create a window using raylib
- Draw shapes to the screen
- Move an object using keyboard input
- Understand the basic structure of a raylib game loop
- Explain variables, functions, and loops in C
- Compile and run a raylib project

---

## 📘 Key Concepts

| Concept | Definition |
|---------|------------|
| **Variable** | A named container that stores a value (e.g., position, speed) |
| **Function** | A reusable block of code that performs a task |
| **Game loop** | The repeating cycle of updating game logic and drawing to the screen |
| **Struct** | A custom data type that groups related values |
| **Update vs Draw** | Update changes game state; Draw renders it visually |

---

## 🎮 What You'll Build

A simple interactive program where a blue square moves with the arrow keys.

---

## 📁 Module Structure

```
module-01-move-the-square/
├── README.md
├── src/
│   ├── main.c
│   └── game.c
├── include/
│   └── game.h
└── build/           (created when you compile)
```

---

## 🧱 Step 1 — Create the Game Struct

**File:** `include/game.h`

```c
#ifndef GAME_H
#define GAME_H

#include "raylib.h"

// Game state container: holds everything the game needs
typedef struct Game {
    Vector2 player_pos;   // Player's position on screen
    float speed;          // Movement speed in pixels per frame
} Game;

// Function declarations
void InitGame(void);
void UpdateGame(void);
void DrawGame(void);
void UnloadGame(void);

#endif
```

**What this does:**

- `#ifndef GAME_H` prevents multiple includes
- `typedef struct Game` groups player position and speed
- Function declarations tell the compiler these functions exist

---

## 🧱 Step 2 — Implement Game Logic

**File:** `src/game.c`

```c
#include "game.h"

// Global game state
static Game game = {0};

// Called once at the start: set initial values
void InitGame(void) {
    game.player_pos = (Vector2){ 400, 225 }; // Center of 800x450 window
    game.speed = 4.0f;                       // Movement speed
}

// Called every frame: update game logic
void UpdateGame(void) {
    // Move left
    if (IsKeyDown(KEY_LEFT)) {
        game.player_pos.x -= game.speed;
    }

    // Move right
    if (IsKeyDown(KEY_RIGHT)) {
        game.player_pos.x += game.speed;
    }

    // Move up
    if (IsKeyDown(KEY_UP)) {
        game.player_pos.y -= game.speed;
    }

    // Move down
    if (IsKeyDown(KEY_DOWN)) {
        game.player_pos.y += game.speed;
    }
}

// Called every frame: draw everything to the screen
void DrawGame(void) {
    // Draw a 40x40 square at the player's position
    DrawRectangleV(game.player_pos, (Vector2){40, 40}, BLUE);
}

// Called once at the end: free resources (none yet)
void UnloadGame(void) {
    // Nothing to unload in Module 1
}
```

**What this does:**

- `static Game game` — stores game state, accessible only within this file
- `InitGame` — sets starting position and speed
- `UpdateGame` — checks arrow keys and moves the square
- `DrawGame` — draws the blue square

---

## 🧱 Step 3 — Create the Main Loop

**File:** `src/main.c`

```c
#include "raylib.h"
#include "game.h"

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 450;

    // Create the window
    InitWindow(screenWidth, screenHeight, "Module 1 - Move the Square");

    InitGame(); // Set up initial game state

    SetTargetFPS(60); // Run at 60 frames per second

    // Main game loop: runs until the window is closed
    while (!WindowShouldClose()) {
        UpdateGame(); // Update all game logic

        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawGame(); // Draw everything
        EndDrawing();
    }

    UnloadGame(); // Clean up resources
    CloseWindow(); // Close the window

    return 0;
}
```

**What this does:**

- Creates an 800x450 window
- Calls `InitGame` to set up game state
- Main loop runs 60 times per second
- Each frame: update logic, clear screen, draw everything
- Cleans up when window closes

---

## 🧪 Step 4 — Build and Run

### From Terminal

First, navigate to the module folder:

```bash
cd modules/module-01-move-the-square
```

Then follow the build instructions for your operating system in the [Setup Guide](/setup/).

### Expected Result

A window appears with a blue square. Use arrow keys to move it around.

---

## 🧩 Exercises

Try these to reinforce what you learned:

1. Change the square's color to green
2. Change the square's size to 60x60
3. Add diagonal movement (hint: combine two arrow keys)
4. Add a speed boost when holding SPACE
5. Keep the square inside the window bounds

---

## 🧠 Pause and Reflect

Take a moment to write down your answers:

- What part of this module felt easiest?
- What part felt confusing?
- How does the game loop relate to a `while` loop in C?
- What does the `Game` struct help you organize?

---

## 🔍 Common Pitfalls

| Problem | Solution |
|---------|----------|
| `'raylib.h' file not found` | Check raylib is installed and include path is correct |
| Square moves off screen | Add boundary checks (exercise 5) |
| Square doesn't move | Check you're using `IsKeyDown`, not `IsKeyPressed` |
| Build errors | Make sure all files are saved before compiling |

---

## 📚 Optional Reading

For deeper understanding of C concepts, read:

- **K&R Chapter 1** — A Tutorial Introduction
  - §1.1: Getting Started
  - §1.2: Variables and Arithmetic Expressions
  - §1.7: Functions

You don't need the book to complete this module — everything is explained here.

---

## 🚀 Stretch Goals

If you want a challenge:

- Add WASD movement
- Add a second square controlled by different keys
- Add a simple "trail" effect
- Add a border around the screen

---

## 📤 Progress Checklist

- [ ] Code compiles without warnings
- [ ] Square moves smoothly with arrow keys
- [ ] Project uses `Game` struct pattern
- [ ] Code is commented
- [ ] Reflection written
- [ ] Folder structure matches template

---

## 📎 raylib Functions Used

| Function | Purpose |
|----------|---------|
| `InitWindow` | Creates the game window |
| `CloseWindow` | Closes the window |
| `SetTargetFPS` | Sets frame rate |
| `WindowShouldClose` | Checks if window should close |
| `BeginDrawing` / `EndDrawing` | Wraps drawing operations |
| `ClearBackground` | Clears the screen |
| `DrawRectangleV` | Draws a rectangle |
| `IsKeyDown` | Checks if a key is held |
| `Vector2` | Stores x,y coordinates |

---

## ➡️ Next Module

🔜 Coming soon