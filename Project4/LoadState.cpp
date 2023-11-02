#include "LoadState.h"
#include "MainMenuState.h"
#include "Button.h"

LoadState::LoadState(RenderWindow* window, stack<State*>* states)
	: State(window, states)
{
	this->initFonts();
	this->initButtons();

	this->background.setSize(Vector2f(1280, 720));
	this->background.setFillColor(Color::Magenta);


	headerText.setCharacterSize(50);
	headerText.setString("Saved sessions:");
	headerText.setFont(font);
	headerText.setFillColor(sf::Color::White);
	headerText.setPosition(Vector2f(490, 80));
	


}

LoadState::~LoadState()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}

}
void LoadState::initButtons()
{

	this->buttons["LOAD_GAME_1"] = new Button(550, 260, 150, 50,
		&this->font, "Load Game",
		Color(70, 70, 70, 200),
		Color(150, 150, 150, 200),
		Color(20, 20, 20, 200));
	this->buttons["LOAD_GAME_2"] = new Button(550, 340, 150, 50,
		&this->font, "Load Game",
		Color(70, 70, 70, 200),
		Color(150, 150, 150, 200),
		Color(20, 20, 20, 200));
	this->buttons["LOAD_GAME_3"] = new Button(550, 420, 150, 50,
		&this->font, "Load Game",
		Color(70, 70, 70, 200),
		Color(150, 150, 150, 200),
		Color(20, 20, 20, 200));
	this->buttons["BACK"] = new Button(550, 600, 150, 50,
		&this->font, "Back",
		Color(70, 70, 70, 200),
		Color(150, 150, 150, 200),
		Color(20, 20, 20, 200));
}
void LoadState::updateButtons()
{
	for (auto& it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}
	if (this->buttons["BACK"]->isPressed())
	{
		this->states->pop();

	}

}

void LoadState::initFonts()
{
	try {
		if (!this->font.loadFromFile("assets/fonts/ShortBaby-Mg2w.ttf")) {
			throw std::runtime_error("Could not find font!");
		}

		if (!snakeImage.loadFromFile("assets/images/snakeImage.png"))
		{
			throw std::runtime_error("Could not find image!");
		}
	}

	catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
	}
}

void LoadState::renderButtons(RenderTarget* target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}
void LoadState::endState()
{
	cout << "Ending LoadMenuState!" << "\n";
}

void LoadState::updateInput(const float& dt)
{
	this->checkForQuit();
}

void LoadState::update(const float& dt)
{
	this->updateMousePosition();
	this->updateInput(dt);
	this->updateButtons();
}

void LoadState::render(RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->background);
	target->draw(this->menuBackground);
	target->draw(this->snakeBackground);
	target->draw(this->snakeImageSprite);
	target->draw(this->headerText);

	this->renderButtons(target);

	
}

