#include "Tetromino.h"

Tetromino::Tetromino(const bool* shape, int dimension, Color color, const Board& board)
    : shape_(shape),
      dimension_(dimension),
      color_(color),
      board_(board),
      board_position_(board.GetWidth()/2 - dimension/2, 0)
{}

void Tetromino::Draw() const {
    for (int y = 0; y < dimension_; y++)
        for (int x = 0; x < dimension_; x++)
            if (shape_[y * dimension_ + x])
                board_.DrawCell(board_position_ + Vec2<int>{x, y});
}