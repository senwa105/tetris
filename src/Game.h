#ifndef GAME_H
#define GAME_H

#include <string>
#include <optional>
#include <memory>
#include <queue>

#include "Board.h"
#include "Tetromino.h"
#include "Randomizer.h"

class Game {
public:
    Game(int width, int height, int fps, std::string title);
    ~Game() noexcept;
    Game(const Game& other) = delete;
    Game& operator=(const Game& other) = delete;

    bool ShouldClose() const;
    void Tick();
    
private:
    Board board_;
    std::unique_ptr<Randomizer> randomizer_;
    std::queue<MinoType> previews;
    Tetromino active_tetromino_;
    std::optional<MinoType> hold_tetromino_;
    bool can_hold_;

    void Draw();
    void Update();
};

#endif