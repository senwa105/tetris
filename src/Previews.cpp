#include "Previews.h"

Previews::Previews() 
    : board_(settings::preview_board_position,
             settings::preview_board_width_height,
             settings::cell_size,
             settings::cell_padding)
{
    if (settings::use_bag_randomizer)
        randomizer_ = std::make_unique<BagRandomizer>();
    else randomizer_ = std::make_unique<CompleteRandomizer>();

    int spawn_y = 0;
    for (int i = 0; i < settings::num_previews; i++) {
        next_minos_.push_back(Tetromino{randomizer_->GetNextTetromino(), board_, Vec2{0, spawn_y}, Tetromino::Rotation::R0});
        spawn_y += settings::preview_vertical_spacing;
    }
}

MinoType Previews::GetNextMino() {
    MinoType next = next_minos_.front().GetMinoType();
    next_minos_.pop_front();
    next_minos_.push_back(Tetromino{randomizer_->GetNextTetromino(), 
                          board_, 
                          Vec2{0, settings::preview_vertical_spacing * (settings::num_previews - 1)}, 
                          Tetromino::Rotation::R0});
    return next;
}

void Previews::Draw() {
    for (Tetromino t : next_minos_)
        t.Draw();
}