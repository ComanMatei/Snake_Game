#include "GameState.h"

GameState::GameState(RenderWindow* window, stack<State*>* states)
	: State(window, states)
{

}

GameState::~GameState()
{

}

void GameState::endState()
{
	cout << " " << "\n";
}

void GameState::updateInput(const float& dt)
{
	this->checkForQuit();
}

void GameState::update(const float& dt)
{
	this->updateMousePosition();
	this->updateInput(dt);
}

void GameState::render(RenderTarget* target)
{
	if (!target)
		target = this->window;
}
