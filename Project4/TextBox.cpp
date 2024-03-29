#include <iostream>
#include <sstream>

#include <SFML\Graphics.hpp>

#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

using namespace std;
using namespace sf;

class TextBox 
{
private:
	Text textBox;
	ostringstream text;
	bool isSelected = false;
	bool hasLimit = false;
	int limit;

	void inputLogic(int charTyped)
	{
		if (charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY)
		{
			text << static_cast<char>(charTyped);
		}
		else if (charTyped == DELETE_KEY)
		{
			if (text.str().length() > 0)
			{
				deleteLastChar();
			}
		}
	}

	void deleteLastChar()
	{
		string t = text.str();
		string newT = "";
		for (int i = 0; i < t.length(); i++)
		{
			newT += t[i];
		}
		text.str("");
		text << newT;

		textBox.setString(text.str() + "_");
	}

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
		target.draw(textBox, states);
	}

public:
	TextBox(){}
	TextBox(int size, Color color, bool sel)
	{
		textBox.setCharacterSize(size);
		textBox.setFillColor(color);
		isSelected = sel;

		if (sel)
		{
			textBox.setString("_");
		}
		else
		{
			textBox.setString("");
		}
	}

	void setFont(Font& font)
	{
		textBox.setFont(font);
	}

	void setPosition(Vector2f poz)
	{
		textBox.setPosition(poz);
	}

	void setLimit(bool ToF)
	{
		hasLimit = ToF;
	}

	void setLimit(bool ToF, int lim)
	{
		hasLimit = ToF;
		limit = lim - 1;
	}

	void setSelected(bool sel)
	{
		isSelected = sel;
		if (!sel)
		{
			string t = text.str();
			string newT = "";
			for (int i = 0; i < t.length() - 1; i++)
			{
				newT += t[i];
			}
			textBox.setString(newT);
		}
	}

	string getText()
	{
		return text.str();
	}

	void drawTo(RenderWindow &window)
	{
		window.draw(textBox);
	}

	void typedOn(Event input)
	{
		if (isSelected)
		{
			int charTyped = input.text.unicode;
			if (charTyped < 128)
			{
				if (hasLimit)
				{
					if (text.str().length() <= limit)
					{
						inputLogic(charTyped);
					}
					else if (text.str().length() > limit && charTyped == DELETE_KEY)
					{
						deleteLastChar();
					}
				}
				else
				{
					inputLogic(charTyped);
				}
			}
		}
	}
};