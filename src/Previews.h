#ifndef PREVIEWS_H
#define PREVIEWS_H

#include <queue>
#include <memory>

#include "MinoType.hpp"
#include "Randomizer.h"
#include "Settings.h"

class Previews {
private:
    std::queue<MinoType> next_minos_;
    std::unique_ptr<Randomizer> randomizer_;

public:
    Previews();
    MinoType GetNextMino();
    void Draw();
};

#endif