#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <stack>

#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <SFML\Network.hpp>

using namespace std;
using namespace sf;

class State
{
private:

protected:
	stack<State*>* states;
	RenderWindow* window;
	bool quit;

	Vector2i mousePosScreen;
	Vector2i mousePosWindow;
	Vector2f mousePosView;

	vector<sf::Texture> textures;
public:
	State(RenderWindow* window, stack<State*>* states);
	virtual ~State();

	const bool& getQuit() const;

	virtual void checkForQuit();

	virtual void endState() = 0;
	virtual void updateMousePosition();
	virtual void updateInput(const float& dt) = 0;
	virtual void update(const float& dt) = 0;
	virtual void render(RenderTarget* target = NULL) = 0;
};

#endif // !STATE_H


