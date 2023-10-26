#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"

class GameState :
    public State
{
private:

public:
    GameState(RenderWindow* window, stack<State*>* states);
    virtual ~GameState();

    void endState();

    void updateInput(const float& dt);
    void update(const float& dt);
    void render(RenderTarget* target = NULL);
};

#endif // !GAMESTATE_H


