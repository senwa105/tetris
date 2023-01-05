#ifndef MINOTYPE_H
#define MINOTYPE_H

#include <cassert>

#include "raylibcpp.h"
#include "Board.h"

struct MinoType {};

struct IMino : public MinoType {
    static constexpr Color color = SKYBLUE;
    static constexpr int dimension = 4;
    static constexpr bool shapes[] 
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

    IMino() {
        static_assert(sizeof(shapes) / sizeof(bool) == 4 * dimension * dimension);
    }
};

struct OMino : public MinoType {
    static constexpr Color color = YELLOW;
    static constexpr int dimension = 2;
    static constexpr bool shapes[] 
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

    OMino() {
        static_assert(sizeof(shapes) / sizeof(bool) == 4 * dimension * dimension);
    }
};

struct TMino : public MinoType {
    static constexpr Color color = MAGENTA;
    static constexpr int dimension = 3;
    static constexpr bool shapes[] 
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

    TMino() {
        static_assert(sizeof(shapes) / sizeof(bool) == 4 * dimension * dimension);
    }
};

struct JMino : public MinoType {
    static constexpr Color color = DARKBLUE;
    static constexpr int dimension = 3;
    static constexpr bool shapes[] 
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

    JMino() {
        static_assert(sizeof(shapes) / sizeof(bool) == 4 * dimension * dimension);
    }
};

struct LMino : public MinoType {
    static constexpr Color color = ORANGE;
    static constexpr int dimension = 3;
    static constexpr bool shapes[] 
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

    LMino() {
        static_assert(sizeof(shapes) / sizeof(bool) == 4 * dimension * dimension);
    }
};

struct SMino : public MinoType {
    static constexpr Color color = GREEN;
    static constexpr int dimension = 3;
    static constexpr bool shapes[] 
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

    SMino() {
        static_assert(sizeof(shapes) / sizeof(bool) == 4 * dimension * dimension);
    }
};

struct ZMino : public MinoType {
    static constexpr Color color = RED;
    static constexpr int dimension = 3;
    static constexpr bool shapes[] 
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

    ZMino() {
        static_assert(sizeof(shapes) / sizeof(bool) == 4 * dimension * dimension);
    }
};

#endif