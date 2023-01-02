#ifndef SETTINGS_H
#define SETTINGS_H

#include "Vec2.hpp"

namespace settings {
    // Window settings
    constexpr int screenWidth = 800;
    constexpr int screenHeight = 600;
    constexpr int fps = 60;

    // Board settings
    constexpr Vec2<int> board_position{200, 200};
    constexpr Vec2<int> board_width_height{10, 20};
    constexpr int cell_size = 20;
    constexpr int cell_padding = 2;
}


#endif