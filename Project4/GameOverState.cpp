#include "GameOverState.h"
#include "GameState.h"
#include "MainMenuState.h"

void GameOverState::initFonts()
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

void GameOverState::initButtons()
{
	this->buttons["MAIN_MENU"] = new Button(550, 340, 150, 50,
		&this->font, "Home",
		Color(70, 70, 70, 200),
		Color(150, 150, 150, 200),
		Color(20, 20, 20, 200));
	this->buttons["TRY_AGAIN"] = new Button(550, 420, 150, 50,
		&this->font, "Try again",
		Color(70, 70, 70, 200),
		Color(150, 150, 150, 200),
		Color(20, 20, 20, 200));
}

GameOverState::GameOverState(RenderWindow* window, stack<State*>* states)
	: State(window, states)
{

	this->initFonts();
	this->initButtons();

	this->background.setSize(Vector2f(1280, 720));
	this->background.setFillColor(sf::Color::Blue);

}

GameOverState::~GameOverState()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}

void GameOverState::endState()
{
	cout << "Ending GameOverState" << "\n";
}

void GameOverState::updateInput(const float& dt)
{
	this->checkForQuit();
}

void GameOverState::updateButtons()
{
	for (auto& it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}

	if (this->buttons["MAIN_MENU"]->isPressed())
	{
		this->states->push(new MainMenuState(this->window, this->states));

	}
	if (this->buttons["TRY_AGAIN"]->isPressed())
	{
		this->states->push(new GameState(this->window, this->states));

	}
	
}

void GameOverState::update(const float& dt)
{
	this->updateMousePosition();
	this->updateInput(dt);

	this->updateButtons();
}

void GameOverState::renderButtons(RenderTarget* target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}


void GameOverState::render(RenderTarget* target)
{
	if (!target)
		target = this->window;
	target->draw(this->background);


	this->renderButtons(target);
}
