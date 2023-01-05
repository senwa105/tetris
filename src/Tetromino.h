#ifndef TETROMINO_H
#define TETROMINO_H

#include <cassert>

#include "raylibcpp.h"
#include "Vec2.hpp"
#include "Board.h"

class Tetromino {
public:
    enum class Rotation {
        R0,
        R90,
        R180,
        R270
    };

private:
    const bool* shapes_;
    const int dimension_;
    const Color color_;
    Board& board_;
    Vec2<int> board_position_;
    Rotation current_rotation_;

    bool PositionHasCollision(Vec2<int> position, Rotation rotation);
    void Lock();

public:
    Tetromino(const bool* shapes, int dimension, Color color, Board& board);
    void Draw() const;
    void RotateCW();
    void Rotate180();
    void RotateCCW();
    void MoveRight();
    void MoveLeft();
    void SoftDrop();
    void HardDrop();
};

class IMino : public Tetromino {
private:
    static constexpr int dimension_ = 4;
    static constexpr bool shapes_[] 
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
    static constexpr Color color_ = SKYBLUE;

public:
    IMino(Board& board)
        : Tetromino(shapes_, dimension_, color_, board)
    {
        static_assert(sizeof(shapes_) / sizeof(bool) == 4 * dimension_ * dimension_);
    }
};

class OMino : public Tetromino {
private:
    static constexpr bool shapes_[] 
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
    static constexpr int dimension_ = 2;
    static constexpr Color color_ = YELLOW;

public:
    OMino(Board& board)
        : Tetromino(shapes_, dimension_, color_, board)
    {
        static_assert(sizeof(shapes_) / sizeof(bool) == 4 * dimension_ * dimension_);
    }
};

class TMino : public Tetromino {
private:
    static constexpr bool shapes_[] 
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
    static constexpr int dimension_ = 3;
    static constexpr Color color_ = MAGENTA;

public:
    TMino(Board& board)
        : Tetromino(shapes_, dimension_, color_, board)
    {
        static_assert(sizeof(shapes_) / sizeof(bool) == 4 * dimension_ * dimension_);
    }
};

class JMino : public Tetromino {
private:
    static constexpr bool shapes_[] 
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
    static constexpr int dimension_ = 3;
    static constexpr Color color_ = DARKBLUE;

public:
    JMino(Board& board)
        : Tetromino(shapes_, dimension_, color_, board)
    {
        static_assert(sizeof(shapes_) / sizeof(bool) == 4 * dimension_ * dimension_);
    }
};

class LMino : public Tetromino {
private:
    static constexpr bool shapes_[] 
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
    static constexpr int dimension_ = 3;
    static constexpr Color color_ = ORANGE;

public:
    LMino(Board& board)
        : Tetromino(shapes_, dimension_, color_, board)
    {
        static_assert(sizeof(shapes_) / sizeof(bool) == 4 * dimension_ * dimension_);
    }
};

class SMino : public Tetromino {
private:
    static constexpr bool shapes_[] 
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
    static constexpr int dimension_ = 3;
    static constexpr Color color_ = GREEN;

public:
    SMino(Board& board)
        : Tetromino(shapes_, dimension_, color_, board)
    {
        static_assert(sizeof(shapes_) / sizeof(bool) == 4 * dimension_ * dimension_);
    }
};

class ZMino : public Tetromino {
private:
    static constexpr bool shapes_[] 
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
    static constexpr int dimension_ = 3;
    static constexpr Color color_ = RED;

public:
    ZMino(Board& board)
        : Tetromino(shapes_, dimension_, color_, board)
    {
        static_assert(sizeof(shapes_) / sizeof(bool) == 4 * dimension_ * dimension_);
    }
};

#endif