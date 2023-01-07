#include "Randomizer.h"

#include "raylibcpp.h"

mino_type::Mino BagRandomizer::GetNextTetromino() {

}

mino_type::Mino CompleteRandomizer::GetNextTetromino() {
    return minos[GetRandomValue(0, minos.size()-1)];
}