#ifndef BOARD_H
#define BOARD_H

#include <vector>

#include "raylibcpp.h"

#include "Vec2.hpp"

class Board {
private:
    class Cell {
    private:
        bool exists_;
        Color color_;
    
    public:
        Cell();
        bool Exists() const;
        void SetColor(Color c);
        Color GetColor() const;
        void Remove();
    };

    std::vector<Cell> cells_;
    Vec2<int> screen_position_;
    int width_;
    int height_;
    int cell_size_;
    int cell_padding_;

public:
    Board(Vec2<int> screen_position , Vec2<int> width_height, int cell_size, int cell_padding);
    int GetWidth() const;
    int GetHeight() const;
    bool CellExists(Vec2<int> position) const;
    void SetCell(Vec2<int> position, Color color);
    void DrawCell(Vec2<int> position, Color color) const;
    void DrawCell(Vec2<int> position) const;
    void DrawBorder() const;
    void Draw() const;
    void ClearLines();
};

#endif