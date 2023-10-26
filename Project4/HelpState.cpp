#include "HelpState.h"

void HelpState::initFonts()
{
	try {
		if (!this->font.loadFromFile("arial.ttf")) {
			throw std::runtime_error("Could not find font!");
		}
	}

	catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
	}
}

HelpState::HelpState(RenderWindow* window, stack<State*>* states)
	: State(window, states)
{

	this->initFonts();

	this->font = font;
	this->text.setString("1. Scopul jocului : \n"
		"   - Scopul jocului Snake este sa controlezi un sarpe care se deplaseaza pe ecran pentru a manca mancarea si a creste in lungime, evitand coliziunile cu el insusi si peretele.\n"
		"2. Miscarea sarpelui:\n"
		"   - Utilizează sagetile directionale ↑ pentru deplasare in sus, sageata jos pentru deplasare in jos, sageata stanga pentru deplasare la stanga si sageata dreapta\n pentru deplasare la dreapta) pentru a controla directia sarpelui.\n"
		"3. Colectarea mancarii:\n"
		"   - Pe ecran vor aparea bucati de mancare reprezentate ca un mar.\n"
		"   - Misiunea ta este sa muti sarpele pentru a-l face sa \"manance\" aceste bucati de mancare.\n"
		"   - Fiecare bucată de mancare mancată iti va creste lungimea sarpelui cu o unitate.\n"
		"4. Evitarea coliziunilor:\n"
		"   - Trebuie sa eviti sa te ciocnesti de marginile ecranului sau de propria coada.\n"
		"   - Dacă capul sarpelui se loveste de o margine sau de coada, jocul se incheie.\n"
		"5. Punctaj:\n"
		"   - Scopul secundar este sa obtii un scor cat mai mare. Fiecare bucata de mancare mancata adauga puncte la scorul tau.\n"
		"   - Scorul tau poate fi comparat cu cel al altor jucatori in mod competitiv.\n"
		"6. Optiuni si variante:\n"
		"   - In functie de versiunea jocului sau platforma pe care o folosesti, pot exista variante si optiuni suplimentare, cum ar fi bonusuri sau obstacole speciale."")");
	this->text.setFont(this->font);
	this->text.setFillColor(Color::White);
	this->text.setCharacterSize(15);



}

void HelpState::endState()
{
	cout << " " << "\n";
}

void HelpState::updateInput(const float& dt)
{
	this->checkForQuit();
}

void HelpState::update(const float& dt)
{
	this->updateMousePosition();
	this->updateInput(dt);
}

void HelpState::render(RenderTarget* target)
{
	if (!target)
		target = this->window;
	target->draw(this->background);
	
	target->draw(this->text);
}

