#include "raylibcpp.h"

#include <cassert>

void raylibcpp::DrawRectangle(Vec2<int> position, Vec2<int> width_height, Color color) {
    int x = position.GetX(), y = position.GetY();
    assert(x >= 0 && x < GetScreenWidth() &&
           y >= 0 && y < GetScreenHeight());
    DrawRectangle(x, y, width_height.GetX(), width_height.GetY(), color);
}