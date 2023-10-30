#include "MainMenuState.h"
#include "HelpState.h"

void MainMenuState::initFonts()
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

void MainMenuState::initButtons()
{

	this->buttons["GAME_STATE"] = new Button(175, 220, 150, 50,
		&this->font, "New Game",
		Color(70, 70, 70, 200),
		Color(150, 150, 150, 200),
		Color(20, 20, 20, 200));

	this->buttons["LOAD_STATE"] = new Button(175, 300, 150, 50,
		&this->font, "Load Game",
		Color(70, 70, 70, 200),
		Color(150, 150, 150, 200),
		Color(20, 20, 20, 200));

	this->buttons["SELECT_COLOR_STATE"] = new Button(175, 380, 150, 50,
		&this->font, "Select Color",
		Color(70, 70, 70, 200),
		Color(150, 150, 150, 200),
		Color(20, 20, 20, 200));

	this->buttons["HELP_STATE"] = new Button(175, 460, 150, 50,
		&this->font, "Help",
		Color(70, 70, 70, 200),
		Color(150, 150, 150, 200),
		Color(20, 20, 20, 200));

	this->buttons["EXIT_STATE"] = new Button(175, 540, 150, 50,
		&this->font, "Quit",
		Color(70, 70, 70, 200),
		Color(150, 150, 150, 200),
		Color(20, 20, 20, 200));

}

MainMenuState::MainMenuState(RenderWindow* window, stack<State*>* states)
	: State(window, states)
{
	this->initFonts();
	this->initButtons();

	this->background.setSize(Vector2f(1280, 720));
	this->background.setFillColor(Color::White);

	snakeImageSprite.setTexture(snakeImage);
	snakeImageSprite.setPosition(550, 20);

	menuBackground.setSize(sf::Vector2f(500, 720));
	menuBackground.setFillColor(sf::Color::Blue);

	snakeBackground.setSize(sf::Vector2f(670,670));
	snakeBackground.setFillColor(sf::Color::Magenta);
	snakeBackground.setPosition(Vector2f(550,20));

	headerText.setCharacterSize(50);
	headerText.setString("Snake Game");
	headerText.setFont(font);
	headerText.setFillColor(sf::Color::White);
	headerText.setPosition(Vector2f(120, 80));

}

MainMenuState::~MainMenuState()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}

void MainMenuState::endState()
{
	cout << "Ending MainMenuState!" << "\n";
}

void MainMenuState::updateInput(const float& dt)
{
	this->checkForQuit();
}

void MainMenuState::updateButtons()
{
	for (auto &it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}

	//New Game
	if (this->buttons["GAME_STATE"]->isPressed())
	{
		this->states->push(new GameState(this->window, this->states));
	}

	// Help
	if (this->buttons["HELP_STATE"]->isPressed())
	{
		this->states->push(new HelpState(this->window, this->states));
	}

	//Quit the game
	if (this->buttons["EXIT_STATE"]->isPressed())
	{
		this->quit = true;
	}
}

void MainMenuState::update(const float& dt)
{
	this->updateMousePosition();
	this->updateInput(dt);

	this->updateButtons();
}

void MainMenuState::renderButtons(RenderTarget* target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}

void MainMenuState::render(RenderTarget* target)
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
