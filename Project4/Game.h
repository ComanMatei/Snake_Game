#ifndef GAME_H
#define GAME_H

#include "MainMenuState.h"
#include "TextBox.cpp"

class Game
{
private:
	RenderWindow* window;
	Event sfEvent;

	Clock dtClock;
	float dt;

	stack<State*> states;
	
	//Initialization
	void initWindow();
	void initStates();

	TextBox gameName;

public:
	//Contructor
	Game();
	virtual ~Game();

	//Regular
	void endApplication();

	//Update
	void updateDt();
	void updateSFMLEvents();
	void update();

	//Render
	void render();

	//Core
	void run();
};

#endif // !GAME_h

