#include "HelpState.h"
#include "MainMenuState.h"

void HelpState::initFonts()
{
	try {
		if (!this->font.loadFromFile("assets/fonts/ShortBaby-Mg2w.ttf")) {
			throw std::runtime_error("Could not find font!");
		}

		if (!snakeHelpImage.loadFromFile("assets/images/snakeHelpImage.jpg"))
		{
			throw std::runtime_error("Could not find image!");
		}
	}

	catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
	}
}


void HelpState::initButtons()
{
	this->buttons["BACK_MENU"] = new Button(0, 20, 150, 50,
		&this->font, "Back",
		Color(70, 70, 70, 200),
		Color(150, 150, 150, 200),
		Color(20, 20, 20, 200));
}

HelpState::HelpState(RenderWindow* window, stack<State*>* states)
	: State(window, states)
{

	this->initFonts();
	this->initButtons();

	spriteSnakeHelpImage.setTexture(snakeHelpImage);
	spriteSnakeHelpImage.setPosition(Vector2f(0, 0));

	this->font = font;
	this->text.setString("1. Scopul jocului : \n"
		"   - Scopul jocului Snake este sa controlezi un sarpe care se deplaseaza pe ecran \n pentru a manca mancarea si a creste in lungime, evitand coliziunile cu el insusi \n si peretele."
		"2. Miscarea sarpelui:\n"
		"   - Utilizeaza sagetile directionale 'sageata sus' pentru deplasare in sus, sageata \n jos pentru deplasare in jos, sageata stanga pentru\n deplasare la stanga si sageata dreapta pentru deplasare la dreapta) pentru a \n controla directia sarpelui.\n"
		"3. Colectarea mancarii:\n"
		"   - Pe ecran vor aparea bucati de mancare reprezentate ca un mar.\n"
		"   - Misiunea ta este sa muti sarpele pentru a-l face sa \"manance\" aceste bucati \n de mancare.\n"
		"   - Fiecare bucata de mancare mancata iti va creste lungimea sarpelui cu o unitate.\n"
		"4. Evitarea coliziunilor:\n"
		"   - Trebuie sa eviti sa te ciocnesti de marginile ecranului sau de propria coada.\n"
		"   - Daca capul sarpelui se loveste de o margine sau de coada, jocul se incheie.\n"
		"5. Punctaj:\n"
		"   - Scopul secundar este sa obtii un scor cat mai mare. Fiecare bucata de mancare \n mancata  adauga puncte la scorul tau.\n"
		"   - Scorul tau poate fi comparat cu cel al altor jucatori in mod competitiv.\n"
		"6. Optiuni si variante:\n"
		"   - In functie de versiunea jocului sau platforma pe care o folosesti, pot exista \n variante si optiuni suplimentare, cum ar fi bonusuri\n sau obstacole speciale."")");
	this->text.setFont(this->font);
	this->text.setFillColor(Color::White);
	text.setPosition(40, 100);
	
	this->text.setCharacterSize(22);

	this->background.setSize(Vector2f(1280, 720));
	this->background.setFillColor(sf::Color::Blue);

}

HelpState::~HelpState()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}

void HelpState::endState()
{
	cout << "Ending HelpState!" << "\n";
}

void HelpState::updateInput(const float& dt)
{
	this->checkForQuit();
}



void HelpState::updateButtons()
{
	for (auto& it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}

	if (this->buttons["BACK_MENU"]->isPressed())
	{
		this->quit = true;
	}
}

void HelpState::update(const float& dt)
{
	this->updateMousePosition();
	this->updateInput(dt);

	this->updateButtons();
}

void HelpState::renderButtons(RenderTarget* target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}

void HelpState::render(RenderTarget* target)
{
	if (!target)
		target = this->window;
	target->draw(this->background);
	target->draw(this->spriteSnakeHelpImage);
	target->draw(this->text);

	this->renderButtons(target);
}

