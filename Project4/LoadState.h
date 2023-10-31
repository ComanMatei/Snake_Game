#ifndef LOADSTATE_H
#define LOADSTATE_H

#include "State.h"
#include "Button.h"

class LoadState :
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
    LoadState(RenderWindow* window, stack<State*>* states);
    virtual ~LoadState();

    void endState();

    void updateInput(const float& dt);
    void updateButtons();
    void update(const float& dt);
    void renderButtons(RenderTarget* target);
    void render(RenderTarget* target);
};

#endif // !LOADSTATE_H
