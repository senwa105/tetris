#include "Tetromino.h"

Tetromino::Tetromino(const bool* shape, int dimension, Color color, const Board& board)
    : shape_(shape),
      dimension_(dimension),
      color_(color),
      board_(board),
      board_position_(board.GetWidth()/2 - dimension/2, 0),
      current_rotation_(Rotation::R0)
{}

void Tetromino::Draw() const {
    for (int y = 0; y < dimension_; y++)
        for (int x = 0; x < dimension_; x++) {
            bool cell = false;
            switch (current_rotation_) {
            case Rotation::R0:
                cell = shape_[y*dimension_ + x];
                break;
            case Rotation::R90:
                cell = shape_[dimension_*(dimension_ - 1) - x*dimension_ + y];
                break;
            case Rotation::R180:
                cell = shape_[dimension_*dimension_ - 1 - y*dimension_  - x];
                break;
            case Rotation::R270:
                cell = shape_[dimension_ - 1 + x*dimension_ - y];
                break;
            default:
                break;
            }
        }
            
}

void Tetromino::RotateCW() {
    static constexpr Rotation clockwise_rotations[] = 
        {Rotation::R90, Rotation::R180, Rotation::R270, Rotation::R0};
    current_rotation_ = clockwise_rotations[static_cast<int>(current_rotation_)];
}

void Tetromino::Rotate180() {
    static constexpr Rotation double_rotations[] = 
        {Rotation::R180, Rotation::R270, Rotation::R0, Rotation::R90};
    current_rotation_ = double_rotations[static_cast<int>(current_rotation_)];
}

void Tetromino::RotateCCW() {
    static constexpr Rotation counter_clockwise_rotations[] = 
        {Rotation::R270, Rotation::R0, Rotation::R90, Rotation::R180};
    current_rotation_ = counter_clockwise_rotations[static_cast<int>(current_rotation_)];
}