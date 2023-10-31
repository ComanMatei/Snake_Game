#ifndef HELPSTATE_H
#define HELPSTATE_H

#include "State.h"
#include "Button.h"

class HelpState :
    public State
{
private:
    RectangleShape background;
    Font font;
    Text text;
    Texture snakeHelpImage;
    Sprite spriteSnakeHelpImage;

    map<string, Button*> buttons;

    void initFonts();
    void initButtons();

public:
    HelpState(RenderWindow* window, stack<State*>* states);
    virtual ~HelpState();

    void endState();

    //Texting
    void setText();

    void updateInput(const float& dt);
    void updateButtons();
    void update(const float& dt);
    void renderButtons(RenderTarget* target);
    void render(RenderTarget* target = NULL);
};

#endif // !HELPSTATE_H

