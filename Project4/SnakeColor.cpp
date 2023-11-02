#include "State.h"

class SnakeColor
{
public:
	SnakeColor() : snakeColor(sf::Color::Green) {

	}

	Color getColor() {
		return snakeColor;
	}

	Color setColor(Color& newColor) {
		snakeColor = newColor;
	}

private:

	Color snakeColor;

};
