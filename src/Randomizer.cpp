#include "Randomizer.h"

#include <algorithm>

#include "raylibcpp.h"
#include "MinoType.hpp"

const MinoType BagRandomizer::GetNextTetromino() {
    if (minos_left.size() == 0)
        minos_left = {0, 1, 2, 3, 4, 5, 6};

    int i = GetRandomValue(0, minos_left.size()-1);
    int next_mino = minos_left[i];
    minos_left.erase(minos_left.begin() + i);
    return static_cast<MinoType>(next_mino);
}

const MinoType CompleteRandomizer::GetNextTetromino() {
    return static_cast<MinoType>(GetRandomValue(0, 6));
}