#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "GameState.h"
#include "Button.h"

class MainMenuState :
    public State
{
private:
    //Variable
    RectangleShape background;
    RectangleShape menuBackground;
    RectangleShape snakeBackground;
    Texture snakeImage;
    Sprite snakeImageSprite;
    Text headerText;
    Font font;

    map<string, Button*> buttons;

    //Function
    void initFonts();
    void initButtons();

public:
    MainMenuState(RenderWindow* window, stack<State*>* states);
    virtual ~MainMenuState();

    void endState();

    void updateInput(const float& dt);
    void updateButtons();
    void update(const float& dt);
    void renderButtons(RenderTarget* target = NULL);
    void render(RenderTarget* target = NULL);

};

#endif // !MAINMENUSTATE_H

