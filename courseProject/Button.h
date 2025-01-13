#ifndef BUTTONS_H
#define BUTTONS_H

#include "SFML/Graphics.hpp"
#include "string"

class MainMenu;
using namespace std;

class Button : public sf::Drawable
{
private:
	
	sf::Text buttonText;
	MainMenu& menu;
	bool(MainMenu::* onPressCallBack)() = nullptr;


public: 

	Button() = default;
	Button(bool(MainMenu::* onPressCallBack)(), MainMenu& menu, sf::Font& font, sf::Vector2f position, string buttonText);
	void onHover(sf::Vector2f& mouseCursor);
	void checkForButtonPress(sf::Vector2f& mouseCursor, sf::Event& e);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	~Button();




};

#endif

