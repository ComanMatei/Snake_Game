#include "NewGameState.h"
#include "MainMenuState.h"
#include "GameState.h"
#include "Button.h"

void NewGameState::initFonts()
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

NewGameState::NewGameState(RenderWindow* window, stack<State*>* states)
	: State(window, states)
{
	this->initFonts();
	this->initButtons();

	this->background.setSize(Vector2f(1280, 720));
	this->background.setFillColor(Color::Blue);

	chooseDifText.setCharacterSize(50);
	chooseDifText.setString("Choose the difficulty");
	chooseDifText.setFont(font);
	chooseDifText.setFillColor(sf::Color::White);
	chooseDifText.setPosition(Vector2f(700, 80));

	chooseNameText.setCharacterSize(50);
	chooseNameText.setString("Choose your name");
	chooseNameText.setFont(font);
	chooseNameText.setFillColor(sf::Color::White);
	chooseNameText.setPosition(Vector2f(100, 80));

	textBoxFont.loadFromFile("assets/fonts/arial.ttf");
	gameName = TextBox(15, Color::Magenta, true);
	gameName.setFont(textBoxFont);
	gameName.setPosition({ 200, 300 });
	gameName.setLimit(true, 10);

}

NewGameState::~NewGameState()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}
void NewGameState::initButtons()
{
	this->buttons["PEACEFUL_DIFFICULTY"] = new Button(850, 200, 150, 50,
		&this->font, "Peaceful",
		Color(70, 70, 70, 200),
		Color(150, 150, 150, 200),
		Color(20, 20, 20, 200));
	this->buttons["HARDCORE_DIFFICULTY"] = new Button(850, 280, 150, 50,
		&this->font, "Hardcore",
		Color(70, 70, 70, 200),
		Color(150, 150, 150, 200),
		Color(20, 20, 20, 200));
	this->buttons["BACK"] = new Button(550, 600, 150, 50,
		&this->font, "Back",
		Color(70, 70, 70, 200),
		Color(150, 150, 150, 200),
		Color(20, 20, 20, 200));
}

void NewGameState::updateButtons()
{
	for (auto& it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}
	if (this->buttons["BACK"]->isPressed())
	{
		this->states->pop();
	}

	//Peaceful Difficulty
	if (this->buttons["PEACEFUL_DIFFICULTY"]->isPressed())
	{
		this->states->push(new GameState(this->window, this->states));
	}
}

void NewGameState::renderButtons(RenderTarget* target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}
void NewGameState::endState()
{
	cout << "Ending NewGameState!" << "\n";
}

void NewGameState::updateInput(const float& dt)
{
	this->checkForQuit();
}

void NewGameState::update(const float& dt)
{
	this->updateMousePosition();
	this->updateInput(dt);
	this->updateButtons();
}

void NewGameState::render(RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->background);
	target->draw(this->chooseDifText);
	target->draw(this->chooseNameText);

	gameName.drawTo(*window);

	this->renderButtons(target);

}