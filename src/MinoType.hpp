#ifndef MINOTYPE_H
#define MINOTYPE_H

#include <cassert>

#include "raylibcpp.h"
#include "Board.h"

enum class MinoType {
    I,
    O,
    T,
    J,
    L,
    S,
    Z
};

// // Overload unary + operator for easy casting to int
// constexpr int  operator+(MinoType a) noexcept {
//     return static_cast<int>(a);
// }

struct Mino {
    const Color color;
    const int dimension;
    const bool* shapes;
};

static constexpr bool i_shapes[]    
    {
        0, 0, 0, 0,     // Rotation 0
        1, 1, 1, 1,
        0, 0, 0, 0,
        0, 0, 0, 0,
    
        0, 0, 1, 0,     // Rotation 90
        0, 0, 1, 0,
        0, 0, 1, 0,
        0, 0, 1, 0,
    
        0, 0, 0, 0,     // Rotation 180
        0, 0, 0, 0,
        1, 1, 1, 1,
        0, 0, 0, 0,
    
        0, 1, 0, 0,     // Rotation 270
        0, 1, 0, 0,
        0, 1, 0, 0,
        0, 1, 0, 0
    };

static constexpr bool o_shapes[]
    {
        1, 1,
        1, 1,

        1, 1,
        1, 1,
        
        1, 1,
        1, 1,
        
        1, 1,
        1, 1
    };

static constexpr bool t_shapes[]
    {
        0, 1, 0,
        1, 1, 1,
        0, 0, 0,

        0, 1, 0,
        0, 1, 1,
        0, 1, 0,

        0, 0, 0,
        1, 1, 1,
        0, 1, 0,

        0, 1, 0,
        1, 1, 0,
        0, 1, 0, 
    };

static constexpr bool j_shapes[] 
    {
        1, 0, 0,
        1, 1, 1,
        0, 0, 0,

        0, 1, 1,
        0, 1, 0,
        0, 1, 0,

        0, 0, 0,
        1, 1, 1,
        0, 0, 1,

        0, 1, 0,
        0, 1, 0,
        1, 1, 0
    };

static constexpr bool l_shapes[] 
    {
        0, 0, 1,
        1, 1, 1,
        0, 0, 0,

        0, 1, 0,
        0, 1, 0,
        0, 1, 1,

        0, 0, 0, 
        1, 1, 1, 
        1, 0, 0, 

        1, 1, 0, 
        0, 1, 0, 
        0, 1, 0
    };

static constexpr bool s_shapes[] 
    {
        0, 1, 1,
        1, 1, 0,
        0, 0, 0,

        0, 1, 0, 
        0, 1, 1,
        0, 0, 1,

        0, 0, 0,
        0, 1, 1,
        1, 1, 0,

        1, 0, 0,
        1, 1, 0, 
        0, 1, 0 
    };

static constexpr bool z_shapes[] 
    {
        1, 1, 0,
        0, 1, 1,
        0, 0, 0,

        0, 0, 1, 
        0, 1, 1, 
        0, 1, 0, 

        0, 0, 0, 
        1, 1, 0, 
        0, 1, 1, 

        0, 1, 0, 
        1, 1, 0, 
        1, 0, 0
    };

static constexpr Mino minos[] = {
    {SKYBLUE,  4, i_shapes},
    {YELLOW,   2, o_shapes},
    {MAGENTA,  3, t_shapes},
    {DARKBLUE, 3, j_shapes},
    {ORANGE,   3, l_shapes},
    {GREEN,    3, s_shapes},
    {RED,      3, z_shapes}
};

#endif