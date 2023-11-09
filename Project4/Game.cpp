#include "Game.h"

void Game::initWindow()
{
	ifstream ifs("Config/window.ini");
	 
	string title = "None";
	VideoMode window_bounds(1280, 720);
	unsigned framerate_limit = 60;
	bool vertical_syns_enable = false;

	if (ifs.is_open())
	{
		getline(ifs, title);
		ifs >> window_bounds.width >> window_bounds.height;
		ifs >> framerate_limit;
		ifs >> vertical_syns_enable;
	}
	ifs.close();

	this->window = new RenderWindow(VideoMode(window_bounds), title);
	this->window->setFramerateLimit(framerate_limit);
	this->window->setVerticalSyncEnabled(vertical_syns_enable);
}

void Game::initStates()
{
	this->states.push(new MainMenuState(this->window, &this->states));
}

//Constructor
Game::Game()
{
	this->initWindow();
	this->initStates();
}

Game::~Game()
{
	delete this->window;

	while (!this->states.empty())
	{
		delete this->states.top();
		this->states.pop();
	}
}

//Functions
void Game::endApplication()
{
	cout << "Ending Application" << "\n";
}

void Game::updateDt()
{
	this->dt = this->dtClock.restart().asSeconds();

}

void Game::updateSFMLEvents()
{
	while (this->window->pollEvent(this->sfEvent))
	{
		if (this->sfEvent.type == Event::Closed)
		{
			this->window->close();
		}
		if (this->sfEvent.type == Event::TextEntered)
		{
			gameName.typedOn(this->sfEvent);
		}
	}
}

void Game::update()
{
	this->updateSFMLEvents();

	if (!this->states.empty())
	{
		this->states.top()->update(this->dt);

		if (this->states.top()->getQuit())
		{
			this->states.top()->endState();
			delete this->states.top();
			this->states.pop();
		}
	}
	else
	{
		this->endApplication();
		this->window->close();
	}
}

void Game::render()
{
	this->window->clear();

	//Render items
	if (!this->states.empty())
		this->states.top()->render();

	this->window->display();
}

void Game::run()
{
	while (this->window->isOpen())
	{
		this->updateDt();
		this->update();
		this->render();
	}
}