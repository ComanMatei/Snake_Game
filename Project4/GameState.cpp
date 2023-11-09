#include "GameState.h"
#include "MainMenuState.h"

void GameState::initFonts()
{
	try {
		if (!this->font.loadFromFile("assets/fonts/ShortBaby-Mg2w.ttf")) {
			throw std::runtime_error("Could not find font!");
		}
	}

	catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
	}

}

void GameState::initButtons()
{
	this->buttons["BACK_MENU"] = new Button(0, 20, 150, 50,
		&this->font, "Back",
		Color(70, 70, 70, 200),
		Color(150, 150, 150, 200),
		Color(20, 20, 20, 200));
}

GameState::GameState(RenderWindow* window, stack<State*>* states)
	: State(window, states)
{

	this->initFonts();
	this->initButtons();

	this->background.setSize(Vector2f(1280, 720));
	this->background.setFillColor(sf::Color::Blue);

}

GameState::~GameState()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}

void GameState::endState()
{
	cout << "Ending GameState" << "\n";
}

void GameState::updateInput(const float& dt)
{
	this->checkForQuit();
}

void GameState::updateButtons()
{
	for (auto& it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}

	if (this->buttons["BACK_MENU"]->isPressed())
	{
		this->states->pop();
	}
}

void GameState::update(const float& dt)
{
	this->updateMousePosition();
	this->updateInput(dt);

	this->updateButtons();
}

void GameState::renderButtons(RenderTarget* target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}


void GameState::render(RenderTarget* target)
{
	if (!target)
		target = this->window;
	target->draw(this->background);


	this->renderButtons(target);
}
