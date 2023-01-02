#ifndef SETTINGS_H
#define SETTINGS_H

#include "Vec2.hpp"

namespace settings {
    // Window settings
    inline constexpr int screenWidth = 800;
    inline constexpr int screenHeight = 600;
    inline constexpr int fps = 60;

    // Board settings
    inline constexpr Vec2<int> board_position{200, 100};
    inline constexpr Vec2<int> board_width_height{10, 20};
    inline constexpr int cell_size = 20;
    inline constexpr int cell_padding = 2;
    inline constexpr int border_width = 3;
    inline constexpr Color border_color = WHITE;
}

#endif