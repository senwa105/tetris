#ifndef GAME_H
#define GAME_H

#include <string>

class Game {
public:
    Game(int width, int height, std::string title);
    ~Game() noexcept;

    bool ShouldClose() const;

    void Tick();
    
private:
    void Update();
    void Draw();
};

#endif