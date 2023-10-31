#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "Button.h"
#include "State.h"

class GameState :
    public State
{
private:
    Font font;
    RectangleShape background;

    map<string, Button*> buttons;

    void initFonts();
    void initButtons();
public:
    GameState(RenderWindow* window, stack<State*>* states);
    virtual ~GameState();

    void endState();

    void updateInput(const float& dt);
    void updateButtons();
    void update(const float& dt);
    void renderButtons(RenderTarget* target);
    void render(RenderTarget* target = NULL);
};

#endif // !GAMESTATE_H


