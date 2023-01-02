#include "Board.h"

#include <cassert>

Board::Cell::Cell()
    : exists_(false),
      color_(WHITE)
{}

void Board::Cell::SetColor(Color c) {
    color_ = c;
    exists_ = true;
}

Color Board::Cell::GetColor() const {
    return color_;
}

void Board::Cell::Remove() {
    exists_ = false;
}

Board::Board(Vector2<int> screen_position , Vector2<int> width_height, int cell_size, int cell_padding)
    : screen_position_(screen_position),
      width_(width_height.GetX()),
      height_(width_height.GetY()),
      cell_size_(cell_size),
      cell_padding_(cell_padding)
{
    assert(width_ > 0 && height_ > 0);
    assert(cell_size_ > 0);
    cells_.resize(width_ * height_);
}

void Board::SetCell(Vector2<int> position, Color c) {
    int x = position.GetX(), y = position.GetY();
    assert(x >= 0 && x < width_ && y >= 0 && y < height_ && "Cell coordinates must be inbounds");
    cells_[y * width_ + x].SetColor(c);
}

void Board::DrawCell(Vector2<int> position) const {
    int x = position.GetX(), y = position.GetY();
    assert(x >= 0 && x < width_ && y >= 0 && y < height_ && "Cell coordinates must be inbounds");

    Vector2<int> top_left = screen_position_ + (position * cell_size_) + cell_padding_;
    DrawRectangle(top_left.GetX(),
                  top_left.GetY(),
                  cell_size_ - cell_padding_,
                  cell_size_ - cell_padding_,
                  cells_[y * width_ + x].GetColor());
}

void Board::Draw() const {
    for (int y = 0; y < height_; y++)
        for (int x = 0; x < width_; x++)
            DrawCell(Vector2<int>{x, y});
}