#include "Randomizer.h"

#include <algorithm>

#include "raylibcpp.h"

const mino_type::Mino* BagRandomizer::GetNextTetromino() {
    if (minos_left.size() == 0)
        minos_left = {0, 1, 2, 3, 4, 5, 6};

    int i = GetRandomValue(0, minos_left.size()-1);
    int next_mino = minos_left[i];
    minos_left.erase(minos_left.begin() + i);
    return minos[next_mino];
}

const mino_type::Mino* CompleteRandomizer::GetNextTetromino() {
    return minos[GetRandomValue(0, minos.size()-1)];
}