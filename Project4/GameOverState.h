#ifndef LOADSTATE_H
#define LOADSTATE_H

#include "State.h"
#include "Button.h"

class GameOverState :
    public State
{
private:
    RectangleShape background;
    RectangleShape menuBackground;
    RectangleShape snakeBackground;
    Texture snakeImage;
    Sprite snakeImageSprite;
    Text headerText;
    Font font;
    map<string, Button*> buttons;
    void initFonts();
    void initButtons();
public:
    GameOverState(RenderWindow* window, stack<State*>* states);
    virtual ~GameOverState();

    void endState();

    void updateInput(const float& dt);
    void updateButtons();
    void update(const float& dt);
    void renderButtons(RenderTarget* target);
    void render(RenderTarget* target);
};

#endif // !GameOverState
