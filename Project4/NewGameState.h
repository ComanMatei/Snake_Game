#ifndef NEWGAMESTATE_H
#define NEWGAMESTATE_H

#include "State.h"
#include "Button.h"
#include "TextBox.cpp"

class NewGameState :
    public State
{
private:
    RectangleShape background;
    Text chooseDifText;
    Text chooseNameText;
    Font font;
    Font textBoxFont;
    map<string, Button*> buttons;

    void initFonts();
    void initButtons();

    TextBox gameName;

public:
    NewGameState(RenderWindow* window, stack<State*>* states);
    ~NewGameState();

    void endState();

    void updateInput(const float& dt);
    void updateButtons();
    void update(const float& dt);
    void renderButtons(RenderTarget* target);
    void render(RenderTarget* target);
};

#endif // !NEWGAMESTATE_H

