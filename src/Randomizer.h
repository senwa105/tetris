#ifndef RANDOMIZER_HPP
#define RANDOMIZER_HPP

#include <array>
#include <vector>

#include "raylibcpp.h"
#include "MinoType.hpp"

class Randomizer {
protected:
    static constexpr std::array<const mino_type::Mino*, 7> minos 
        {
            &mino_type::I,
            &mino_type::O,
            &mino_type::T,
            &mino_type::J,
            &mino_type::L,
            &mino_type::S,
            &mino_type::Z
        };

public:
    virtual const mino_type::Mino* GetNextTetromino() = 0;
};

class BagRandomizer : public Randomizer {
private:
    std::vector<int> minos_left {0, 1, 2, 3, 4, 5, 6};

public:
    const mino_type::Mino* GetNextTetromino() override;
};

class CompleteRandomizer : public Randomizer {
public:
    const mino_type::Mino* GetNextTetromino() override;
};

#endif