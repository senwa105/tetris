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

Board::Board(int x, int y, int width, int height, int cell_size, int cell_padding)
    : screen_x_(x),
      screen_y_(y),
      width_(width),
      height_(height),
      cell_size_(cell_size),
      cell_padding_(cell_padding)
{
    assert(width_ > 0 && height_ > 0);
    assert(cell_size_ > 0);
    cells_.resize(width_ * height_);
}

void Board::SetCell(int x, int y, Color c) {
    assert(x >= 0 && x < width_ && y >= 0 && y < height_ && "Cell coordinates must be inbounds");
    cells_[y * width_ + x].SetColor(c);
}

void Board::DrawCell(int x, int y) const {
    assert(x >= 0 && x < width_ && y >= 0 && y < height_ && "Cell coordinates must be inbounds");
    DrawRectangle(screen_x_ + x * cell_size_ + cell_padding_,
                  screen_y_ + y * cell_size_ + cell_padding_,
                  cell_size_ - cell_padding_,
                  cell_size_ - cell_padding_,
                  cells_[y * width_ + x].GetColor());
}

void Board::Draw() const {
    for (int y = 0; y < height_; y++)
        for (int x = 0; x < width_; x++)
            DrawCell(x, y);
}