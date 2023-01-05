#ifndef TETROMINO_H
#define TETROMINO_H

#include <cassert>

#include "raylibcpp.h"
#include "MinoType.h"
#include "Vec2.hpp"
#include "Board.h"

class Tetromino {
private:
    enum class Rotation {
            R0,
            R90,
            R180,
            R270
    };

    MinoType& type_;
    Board& board_;
    Vec2<int> board_position_;
    Rotation current_rotation_;

    bool PositionHasCollision(Vec2<int> position, Rotation rotation) const;
    void Lock() const;

public:
    Tetromino(MinoType& type, Board& board);
    Tetromino& operator=(const Tetromino& other);
    void Draw() const;
    void RotateCW();
    void Rotate180();
    void RotateCCW();
    void MoveRight();
    void MoveLeft();
    void SoftDrop();
    void HardDrop();
};

#endif