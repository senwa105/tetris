#include "Randomizer.h"

#include <algorithm>

#include "raylibcpp.h"
#include "MinoType.hpp"

const MinoType BagRandomizer::GetNextTetromino() {
    if (minos_left_.size() == 0)
        minos_left_ = {
            MinoType::I,
            MinoType::O,
            MinoType::T,
            MinoType::J,
            MinoType::L,
            MinoType::S,
            MinoType::Z
        };

    int i = GetRandomValue(0, minos_left_.size()-1);
    MinoType next_mino = minos_left_[i];
    minos_left_.erase(minos_left_.begin() + i);
    return next_mino;
}

const MinoType CompleteRandomizer::GetNextTetromino() {
    return static_cast<MinoType>(GetRandomValue(0, 6));
}