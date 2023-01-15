#ifndef SETTINGS_H
#define SETTINGS_H

#include "raylibcpp.h"
#include "Vec2.hpp"

namespace settings {
    // Window settings
    inline constexpr int screenWidth = 800;
    inline constexpr int screenHeight = 600;
    inline constexpr int fps = 60;  // set to 0 for uncapped framerate

    // Board settings
    inline constexpr Vec2<int> board_position{200, 100};
    inline constexpr Vec2<int> board_width_height{10, 20};
    inline constexpr int cell_size = 20;
    inline constexpr int cell_padding = 2;
    inline constexpr int border_width = 3;
    inline constexpr Color border_color = WHITE;

    // Controls
    inline constexpr KeyboardKey rotate_cw = KEY_F;
    inline constexpr KeyboardKey rotate_180 = KEY_E;
    inline constexpr KeyboardKey rotate_ccw = KEY_D;
    inline constexpr KeyboardKey hold = KEY_S;
    inline constexpr KeyboardKey right = KEY_RIGHT;
    inline constexpr KeyboardKey left = KEY_LEFT;
    inline constexpr KeyboardKey soft_drop = KEY_DOWN;
    inline constexpr KeyboardKey hard_drop = KEY_SPACE;

    // Game settings
    inline constexpr bool use_bag_randomizer = true;
    inline constexpr int num_previews = 5;
}

#endif