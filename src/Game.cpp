#include "Game.h"

#include <cassert>

#include "raylibcpp.h"
#include "Settings.h"

Game::Game(int width, int height, int fps, std::string title)
    : board_(settings::board_position,
             settings::board_width_height,
             settings::cell_size,
             settings::cell_padding),
      active_tetromino_(JMino{board_}),
      hold_tetromino_(),
      can_hold_(true)
{
    assert(!GetWindowHandle() && "Window is already open");
    SetConfigFlags(FLAG_VSYNC_HINT);
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

void Game::Draw() {
    ClearBackground(BLACK);
    board_.Draw();
    active_tetromino_.Draw();
    DrawFPS(10, 10);
}

void Game::Update() {
    if (IsKeyPressed(settings::rotate_cw))
        active_tetromino_.RotateCW();
    if (IsKeyPressed(settings::rotate_ccw))
        active_tetromino_.RotateCCW();
    if (IsKeyPressed(settings::rotate_180))
        active_tetromino_.Rotate180();
    if (IsKeyDown(settings::right))
        active_tetromino_.MoveRight();
    if (IsKeyDown(settings::left))
        active_tetromino_.MoveLeft();
}