#include "Tetromino.h"

#include <iostream>

#include "MinoType.hpp"

Tetromino::Tetromino(const MinoType type, Board& board)
    : type_(type),
      board_(board),
      board_position_(board.GetWidth()/2 - minos[static_cast<int>(type)].dimension/2, 0),
      current_rotation_(Rotation::R0)
{}

Tetromino& Tetromino::operator=(const Tetromino& other) {
    type_ = other.type_;
    board_ = other.board_;
    board_position_ = other.board_position_;
    current_rotation_ = other.current_rotation_;
    return *this;
}

bool Tetromino::PositionHasCollision(Vec2<int> position, Rotation rotation) const {
    int dimension = minos[static_cast<int>(type_)].dimension;
    for (int y = 0; y < dimension; y++)
        for (int x = 0; x < dimension; x++) {
            int rotation_chunk = static_cast<int>(rotation) * dimension * dimension;
            bool cell = minos[static_cast<int>(type_)].shapes[rotation_chunk + y*dimension + x];
            if (cell) {
                int cell_x = position.GetX() + x;
                int cell_y = position.GetY() + y;
                if (cell_x < 0 || cell_x >= board_.GetWidth() || cell_y < 0 || cell_y >= board_.GetHeight())
                    return true;
                if (board_.CellExists({cell_x, cell_y}))
                    return true;
            }
        }

    return false;
}

void Tetromino::Draw() const {
    int dimension = minos[static_cast<int>(type_)].dimension;
    for (int y = 0; y < dimension; y++)
        for (int x = 0; x < dimension; x++) {
            // find the block that describes the shape of the current rotation
            // eg, first dimension*dimension entries describes shape of rotation 0
            int rotation_chunk = static_cast<int>(current_rotation_) * dimension * dimension;
            bool cell = minos[static_cast<int>(type_)].shapes[rotation_chunk + y*dimension + x];
            if (cell)
				board_.DrawCell(board_position_ + Vec2<int>{x, y}, minos[static_cast<int>(type_)].color);
        }
            
}

void Tetromino::RotateCW() {
    static constexpr Rotation clockwise_rotations[] = 
        {Rotation::R90, Rotation::R180, Rotation::R270, Rotation::R0};
    Rotation new_rotation = clockwise_rotations[static_cast<int>(current_rotation_)];
    if (!PositionHasCollision(board_position_, new_rotation))
        current_rotation_ = new_rotation;
}

void Tetromino::Rotate180() {
    static constexpr Rotation double_rotations[] = 
        {Rotation::R180, Rotation::R270, Rotation::R0, Rotation::R90};
    Rotation new_rotation = double_rotations[static_cast<int>(current_rotation_)];
    if (!PositionHasCollision(board_position_, new_rotation))
        current_rotation_ = new_rotation;
}

void Tetromino::RotateCCW() {
    static constexpr Rotation counter_clockwise_rotations[] = 
        {Rotation::R270, Rotation::R0, Rotation::R90, Rotation::R180};
    Rotation new_rotation = counter_clockwise_rotations[static_cast<int>(current_rotation_)];
    if (!PositionHasCollision(board_position_, new_rotation))
        current_rotation_ = new_rotation;
}

void Tetromino::MoveRight() {
    if (!PositionHasCollision(board_position_ + Vec2<int>{1, 0}, current_rotation_))
        board_position_ += {1, 0};
}

void Tetromino::MoveLeft() {
    if (!PositionHasCollision(board_position_ + Vec2<int>{-1, 0}, current_rotation_))
            board_position_ += {-1, 0};
}

void Tetromino::Lock() const {
    int dimension = minos[static_cast<int>(type_)].dimension;
    for (int y = 0; y < dimension; y++)
        for (int x = 0; x < dimension; x++) {
            int rotation_chunk = static_cast<int>(current_rotation_) * dimension * dimension;
            bool cell = minos[static_cast<int>(type_)].shapes[rotation_chunk + y*dimension + x];
            if (cell)
				board_.SetCell(board_position_ + Vec2<int>{x, y}, minos[static_cast<int>(type_)].color);
        }

    board_.ClearLines();
}

void Tetromino::SoftDrop() {
    if (!PositionHasCollision(board_position_ + Vec2<int>{0, 1}, current_rotation_))
        board_position_ += {0, 1};
}

void Tetromino::HardDrop() {
    while (!PositionHasCollision(board_position_ + Vec2<int>{0, 1}, current_rotation_))
        board_position_ += {0, 1};

    Lock();
}