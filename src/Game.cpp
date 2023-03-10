#include "Game.h"

#include <cassert>
#include <memory>

#include "raylibcpp.h"
#include "Settings.h"
#include "MinoType.hpp"

Game::Game(int width, int height, int fps, std::string title)
    : board_(settings::board_position,
             settings::board_width_height,
             settings::cell_size,
             settings::cell_padding),
      previews_(),
      active_tetromino_(MinoType::I, board_),   // dummy value
      hold_tetromino_(),
      can_hold_(true)
{
    active_tetromino_ = Tetromino(previews_.GetNextMino(), board_);

    assert(!GetWindowHandle() && "Window is already open");
    SetConfigFlags(FLAG_VSYNC_HINT);
    SetTargetFPS(fps);
    InitWindow(width, height, title.c_str());
}

Game::~Game() {
    // assert(GetWindowHandle() && "Window is already closed");
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
    previews_.Draw();
    DrawFPS(10, 10);
}

void Game::Update() {
    if (IsKeyPressed(settings::rotate_cw))
        active_tetromino_.RotateCW();
    if (IsKeyPressed(settings::rotate_ccw))
        active_tetromino_.RotateCCW();
    if (IsKeyPressed(settings::rotate_180))
        active_tetromino_.Rotate180();
    if (IsKeyPressed(settings::right))
        active_tetromino_.MoveRight();
    if (IsKeyPressed(settings::left))
        active_tetromino_.MoveLeft();
    if (IsKeyDown(settings::soft_drop))
        active_tetromino_.SoftDrop();
    if (IsKeyPressed(settings::hard_drop)) {
        active_tetromino_.HardDrop();
        active_tetromino_ = Tetromino(previews_.GetNextMino(), board_);
    }
}