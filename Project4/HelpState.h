#ifndef HELPSTATE_H
#define HELPSTATE_H

#include "State.h"

class HelpState :
    public State
{
private:
    RectangleShape background;
    Font font;
    Text text;

    void initFonts();

public:
    HelpState(RenderWindow* window, stack<State*>* states);
    virtual ~HelpState() = default;

    void endState();

    //Texting
    void setText();

    void updateInput(const float& dt);
    void update(const float& dt);
    void render(RenderTarget* target = NULL);
};

#endif // !HELPSTATE_H

