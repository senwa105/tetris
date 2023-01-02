#include "Game.h"

#include <cassert>

#include "raylib.h"

Game::Game(int width, int height, int fps, std::string title) {
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
    ClearBackground(RAYWHITE);
}