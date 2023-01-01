#include "raylib.h"

#include "Game.h"

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 450;

    Game game{screenWidth, screenHeight, "Tetris Example"};

    while (!game.ShouldClose()) {
        game.Tick();
    }
}