#ifndef TETROMINO_H
#define TETROMINO_H

#include "raylibcpp.h"
#include "Vec2.hpp"
#include "Board.h"

class Tetromino {
private:
    const bool* shape_;
    const int dimension_;
    const Color color_;
    Vec2<int> board_position_;

public:
    Tetromino(const bool* shape, int dimension, Color color, const Board& board);
};

class IMino : public Tetromino {
private:
    static constexpr bool shape[] {0, 0, 0, 0,
                                   1, 1, 1, 1,
                                   0, 0, 0, 0,
                                   0, 0, 0, 0};
    static constexpr int dimension = 4;
    static constexpr Color color = SKYBLUE;
};

class OMino : public Tetromino {
private:
    static constexpr bool shape[] {1, 1,
                                   1, 1};
    static constexpr int dimension = 2;
    static constexpr Color color = YELLOW;
};

class TMino : public Tetromino {
private:
    static constexpr bool shape[] {0, 1, 0,
                                   1, 1, 1,
                                   0, 0, 0};
    static constexpr int dimension = 3;
    static constexpr Color color = MAGENTA;
};

class JMino : public Tetromino {
private:
    static constexpr bool shape[] {1, 0, 0,
                                   1, 1, 1,
                                   0, 0, 0};
    static constexpr int dimension = 3;
    static constexpr Color color = DARKBLUE;
};

class LMino : public Tetromino {
private:
    static constexpr bool shape[] {0, 0, 1,
                                   1, 1, 1,
                                   0, 0, 0};
    static constexpr int dimension = 3;
    static constexpr Color color = ORANGE;
};

class SMino : public Tetromino {
private:
    static constexpr bool shape[] {0, 1, 1,
                                   1, 1, 0,
                                   0, 0, 0};
    static constexpr int dimension = 3;
    static constexpr Color color = GREEN;
};

class ZMino : public Tetromino {
private:
    static constexpr bool shape[] {1, 1, 0,
                                   0, 1, 1,
                                   0, 0, 0};
    static constexpr int dimension = 3;
    static constexpr Color color = RED;
};

#endif