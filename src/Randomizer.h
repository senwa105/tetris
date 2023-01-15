#ifndef RANDOMIZER_HPP
#define RANDOMIZER_HPP

#include <array>
#include <vector>
#include <chrono>

#include "raylibcpp.h"
#include "MinoType.hpp"

class Randomizer {
public:
    Randomizer() { SetRandomSeed(std::time(0)); }
    virtual const MinoType GetNextTetromino() = 0;
};

class BagRandomizer : public Randomizer {
private:
    std::vector<int> minos_left {0, 1, 2, 3, 4, 5, 6};

public:
    const MinoType GetNextTetromino() override;
};

class CompleteRandomizer : public Randomizer {
public:
    const MinoType GetNextTetromino() override;
};

#endif