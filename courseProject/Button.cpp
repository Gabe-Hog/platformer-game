#include "Button.h"
#include "MainMenu.h"
#include <windows.h>


Button::Button(bool (MainMenu::*onPressCallBack)(), MainMenu& menu, sf::Font& font, sf::Vector2f position, string buttonText)
	: onPressCallBack(onPressCallBack), menu(menu)
{

	this->buttonText.setFont(font);
	this->buttonText.setPosition(position);
	this->buttonText.setCharacterSize(18);
	this->buttonText.setString(buttonText);
	
	this->buttonText.setFillColor(sf::Color::White);
	
}

void Button::onHover(sf::Vector2f& mouseCursor)
{
	sf::FloatRect buttonBounds = this->buttonText.getGlobalBounds();
	if (buttonBounds.contains(mouseCursor))
	{
		this->buttonText.setFillColor(sf::Color::Black);
	}
	else {
		this->buttonText.setFillColor(sf::Color::White);
	}
}

void Button::checkForButtonPress(sf::Vector2f& mouseCursor, sf::Event& e)
{
	sf::FloatRect buttonBounds = this->buttonText.getGlobalBounds();
	
	if (buttonBounds.contains(mouseCursor)) 
	{
		
		(this->menu.*onPressCallBack)();
			
	}
	
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(buttonText);
}

Button::~Button()
{
}
