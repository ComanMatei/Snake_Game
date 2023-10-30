#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>

#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

using namespace std;
using namespace sf;

enum button_states
{ 
	BTN_IDLE = 0,
	BTN_HOVER,
	BTN_ACTIVE
};

class Button
{
private:
	short unsigned buttonState;

	RectangleShape shape;
	Font* font;
	Text text;

	Color idleColor;
	Color hoverColor;
	Color activeColor;

public:
	Button(float x, float y, float width, float height, 
		Font* font, string text, 
		Color idleColor, Color hoverColor, Color activeColor);
	~Button();

	//Accesors
	const bool isPressed() const;

	//Function
	void update(const Vector2f mousePos);
	void render(RenderTarget* target);
};

#endif // !BUTTON_H


