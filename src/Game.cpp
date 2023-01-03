#include "Game.h"

#include <cassert>

#include "raylibcpp.h"
#include "Settings.h"

Game::Game(int width, int height, int fps, std::string title)
    : board_(settings::board_position,
             settings::board_width_height,
             settings::cell_size,
             settings::cell_padding)
{
    assert(!GetWindowHandle() && "Window is already open");
    SetTargetFPS(fps);
    InitWindow(width, height, title.c_str());
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