#ifndef BOARD_H
#define BOARD_H

#include <vector>

#include "raylib.h"

#include "Vec2.hpp"

class Board {
private:
    class Cell {
    private:
        bool exists_;
        Color color_;
    
    public:
        Cell();
        void SetColor(Color c);
        Color GetColor() const;
        void Remove();
    };

    std::vector<Cell> cells_;
    const Vec2<int> screen_position_;
    const int width_;
    const int height_;
    const int cell_size_;
    const int cell_padding_;

public:
    Board(Vec2<int> screen_position , Vec2<int> width_height, int cell_size, int cell_padding);
    void SetCell(Vec2<int> position, Color c);
    void DrawCell(Vec2<int> position) const;
    void Draw() const;
};

#endif