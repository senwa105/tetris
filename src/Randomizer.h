#ifndef RANDOMIZER_HPP
#define RANDOMIZER_HPP

#include <array>

#include "raylibcpp.h"
#include "MinoType.hpp"

class Randomizer {
protected:
    static constexpr std::array<mino_type::Mino, 7> minos 
        {
            mino_type::I,
            mino_type::O,
            mino_type::T,
            mino_type::J,
            mino_type::L,
            mino_type::S,
            mino_type::Z
        };

public:
    virtual mino_type::Mino GetNextTetromino() = 0;
};

class BagRandomizer : public Randomizer {
private:
    std::array<bool, minos.size()> used;

public:
    mino_type::Mino GetNextTetromino() override;
};

class CompleteRandomizer : public Randomizer {
public:
    mino_type::Mino GetNextTetromino() override;
};

#endif