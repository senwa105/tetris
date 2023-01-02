#include "raylib.h"

#include "Game.h"

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 600;
    const int fps = 60;

    Game game{screenWidth, screenHeight, fps, "Tetris Example"};

    while (!game.ShouldClose()) {
        game.Tick();
    }
}