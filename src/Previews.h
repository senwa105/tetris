#ifndef PREVIEWS_H
#define PREVIEWS_H

#include <deque>
#include <memory>

#include "Tetromino.h"
#include "Randomizer.h"
#include "Settings.h"

class Previews {
private:
    std::deque<Tetromino> next_minos_;
    std::unique_ptr<Randomizer> randomizer_;
    Board board_;

    void AddNextMino();

public:
    Previews();
    MinoType GetNextMino();
    void Draw();
};

#endif