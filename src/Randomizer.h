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
    std::vector<MinoType> minos_left_ = {
        MinoType::I,
        MinoType::O,
        MinoType::T,
        MinoType::J,
        MinoType::L,
        MinoType::S,
        MinoType::Z
    };

public:
    BagRandomizer() = default;
    BagRandomizer(std::vector<MinoType> minos_left)
        : minos_left_(minos_left)
    {}
    
    const MinoType GetNextTetromino() override;
};

class CompleteRandomizer : public Randomizer {
public:
    const MinoType GetNextTetromino() override;
};

#endif