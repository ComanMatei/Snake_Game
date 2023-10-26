#include "State.h"

State::State(RenderWindow* window, stack<State*>* states)
{
	this->window = window;
	this->states = states;
	this->quit = false;
}

State::~State()
{

}

const bool& State::getQuit() const
{
	return this->quit;
}

void State::checkForQuit()
{
	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		this->quit = true;
	}
}

void State::updateMousePosition()
{
	this->mousePosScreen = Mouse::getPosition();
	this->mousePosWindow = Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(Mouse::getPosition(*this->window));
}
