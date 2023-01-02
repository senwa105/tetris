#ifndef RAYLIBCPP_H
#define RAYLIBCPP_H

#include "raylib.h"

#include "Vec2.hpp"

namespace raylibcpp {
    void DrawRectangle(Vec2<int> position, Vec2<int> width_height, Color color);
    void DrawRectangleLinesEx(Vec2<int> position, Vec2<int> width_height, int line_thickness, Color color);
}

#endif