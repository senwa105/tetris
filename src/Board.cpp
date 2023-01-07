#include "Board.h"

#include <cassert>
#include <algorithm>

#include "Settings.h"

Board::Cell::Cell()
    : exists_(false),
      color_(WHITE)
{}

bool Board::Cell::Exists() const {
    return exists_;
}

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

Board::Board(Vec2<int> screen_position , Vec2<int> width_height, int cell_size, int cell_padding)
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

int Board::GetWidth() const {
    return width_;
}

int Board::GetHeight() const {
    return height_;
}

bool Board::CellExists(Vec2<int> position) const {
    return cells_[position.GetY()*width_ + position.GetX()].Exists();
}

void Board::SetCell(Vec2<int> position, Color color) {
    int x = position.GetX(), y = position.GetY();
    assert(x >= 0 && x < width_ && y >= 0 && y < height_ && "Cell coordinates must be inbounds");
    cells_[y * width_ + x].SetColor(color);
}

void Board::DrawCell(Vec2<int> position, Color color) const {
    int x = position.GetX(), y = position.GetY();
    assert(x >= 0 && x < width_ && y >= 0 && y < height_ && "Cell coordinates must be inbounds");

    Vec2<int> top_left = screen_position_ + (position * cell_size_) + cell_padding_;
    Vec2<int> width_height = {cell_size_ - cell_padding_, cell_size_ - cell_padding_};
    raylibcpp::DrawRectangle(top_left, width_height, color);
}

void Board::DrawCell(Vec2<int> position) const {
    DrawCell(position, cells_[position.GetY() * width_ + position.GetX()].GetColor());
}

void Board::DrawBorder() const {
    raylibcpp::DrawRectangleLinesEx(screen_position_ - settings::border_width,
                                    Vec2{width_ * cell_size_, height_ * cell_size_} + settings::cell_padding + settings::border_width * 2,
                                    settings::border_width,
                                    settings::border_color);
}

void Board::Draw() const {
    for (int y = 0; y < height_; y++)
        for (int x = 0; x < width_; x++)
            if (CellExists({x, y}))
                DrawCell({x, y});

    DrawBorder();
}

void Board::ClearLines() {
    int row = 0;
    auto row_start = cells_.begin();
    for (int i = 0; i < height_; i++) {
        if (std::all_of(row_start, row_start + width_, [](Cell c) { return c.Exists(); })) {
            // starting from bottom right corner, set each cell to the cell above it
            for (int j = (row+1) * width_ - 1; j >= width_; j--)
                cells_[j] = cells_[j - width_];
            // remove all cells in the topmost row
            for (int j = 0; j < width_; j++)
                cells_[j].Remove();
        }

        row++;
        row_start += width_;
    }

    
}