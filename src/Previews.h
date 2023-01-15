#ifndef PREVIEWS_H
#define PREVIEWS_H

#include <queue>
#include <memory>

#include "Tetromino.h"
#include "Randomizer.h"
#include "Settings.h"

class Previews {
private:
    std::queue<Tetromino> next_minos_;
    std::unique_ptr<Randomizer> randomizer_;
    Board board_;

public:
    Previews();
    MinoType GetNextMino();
    void Draw();
};

#endif