#include "Game.h"

#include <cassert>

#include "raylib.h"

Game::Game(int width, int height, int fps, std::string title)
    : board_(200, 200, 10, 20, 15, 2)
{
    assert(!GetWindowHandle() && "Window is already open");
    SetTargetFPS(fps);
    InitWindow(width, height, title.c_str());

    for (int y = 0; y < 20; y++)
        for (int x = 0; x < 10; x++)
            board_.SetCell(x, y, RED);
}

Game::~Game() {
    assert(GetWindowHandle() && "Window is already closed");
    CloseWindow();
}

bool Game::ShouldClose() const {
    return WindowShouldClose();
}

void Game::Tick() {
    BeginDrawing();
    Update();
    Draw();
    EndDrawing();
}

void Game::Update() {

}

void Game::Draw() {
    ClearBackground(BLACK);
    board_.Draw();
}