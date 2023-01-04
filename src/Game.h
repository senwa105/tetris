#ifndef GAME_H
#define GAME_H

#include <string>

#include "Board.h"
#include "Tetromino.h"

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
    Tetromino active_tetromino_;
    Tetromino hold_tetromino_;
    bool can_hold_;

    void Draw();
    void Update();
};

#endif