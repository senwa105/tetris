#include "raylib.h"

#include "Game.h"
#include "Settings.h"

int main(void) {
    Game game{settings::screenWidth, 
              settings::screenHeight, 
              settings::fps, 
              "Tetris"};

    while (!game.ShouldClose()) {
        game.Tick();
    }
}