#include "raylibcpp.h"

#include <cassert>

void raylibcpp::DrawRectangle(Vec2<int> position, Vec2<int> width_height, Color color) {
    int x = position.GetX(), y = position.GetY();
    assert(x >= 0 && x < GetScreenWidth() &&
           y >= 0 && y < GetScreenHeight() &&
           "Coordinates must be within screen bounds");
    DrawRectangle(x, y, width_height.GetX(), width_height.GetY(), color);
}

void raylibcpp::DrawRectangleLinesEx(Vec2<int> position, Vec2<int> width_height, int line_thickness, Color color) {
    int x = position.GetX(), y = position.GetY();
    assert(x >= 0 && x < GetScreenWidth() &&
           y >= 0 && y < GetScreenHeight() &&
           "Coordinates must be within screen bounds");
    assert(line_thickness > 0);
    DrawRectangleLinesEx({static_cast<float>(x),
                          static_cast<float>(y),
                          static_cast<float>(width_height.GetX()), 
                          static_cast<float>(width_height.GetY())}, 
                          line_thickness, 
                          color);
}