#ifndef MINOTYPE_H
#define MINOTYPE_H

#include <cassert>

#include "raylibcpp.h"
#include "Board.h"

namespace mino_type {

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

static constexpr Mino I = {SKYBLUE, 4, i_shapes};
static constexpr Mino O = {YELLOW, 2, o_shapes};
static constexpr Mino T = {MAGENTA, 3, t_shapes};
static constexpr Mino J = {DARKBLUE, 3, j_shapes};
static constexpr Mino L = {ORANGE, 3, l_shapes};
static constexpr Mino S = {GREEN, 3, s_shapes};
static constexpr Mino Z = {RED, 3, z_shapes};

}

#endif