#ifndef BOARD_H
#define BOARD_H

#include <vector>

#include "raylib.h"

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
    const int screen_x_;
    const int screen_y_;
    const int width_;
    const int height_;
    const int cell_size_;
    const int cell_padding_;

public:
    Board(int x, int y, int width, int height, int cell_size, int cell_padding);
    void SetCell(int x, int y, Color c);
    void DrawCell(int x, int y) const;
    void Draw() const;
};

#endif