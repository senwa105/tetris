#ifndef TETROMINO_H
#define TETROMINO_H

#include <cassert>

#include "raylibcpp.h"
#include "MinoType.hpp"
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
    MinoType type_;
    Board& board_;
    Vec2<int> board_position_;
    Rotation current_rotation_;

    bool PositionHasCollision(Vec2<int> position, Rotation rotation) const;
    void Lock() const;

public:
    Tetromino(MinoType type, Board& board);
    Tetromino(MinoType type, Board& board, Vec2<int> board_position, Rotation rotation);
    Tetromino& operator=(const Tetromino& other);
    MinoType GetMinoType() const;
    void SetBoardPosition(Vec2<int> board_position);
    void Draw() const;
    void RotateCW();
    void Rotate180();
    void RotateCCW();
    void MoveRight();
    void MoveLeft();
    void SoftDrop();
    void HardDrop();

    // Draw tetromino in arbitrary location
    static void Draw(MinoType type, Vec2<int> position);
};

#endif