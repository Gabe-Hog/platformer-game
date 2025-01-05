#ifndef MAINMENU_H
#define MAINMENU_H
#include <fstream>
#include <vector>
#include <memory>
#include <string>
#include "SFML/Graphics.hpp"
#include "Button.h"
#include "assetHandler.h"


using namespace std;
class MainMenu
{

private:
	sf::RenderWindow& window;
	sf::Vector2f mouseCursorPosition;
	sf::Font textFont;
	sf::Text text;
	sf::Text scoreBoardText;
	assetHandler<sf::Font>* fontHandler;
	vector<unique_ptr<Button>> menuButtons;
	
	bool play = false;

public:

	MainMenu() = default;
	MainMenu(sf::RenderWindow& window, assetHandler<sf::Font>* handler, string infoText = "Hello World!");
	~MainMenu();
	void displayMenu();
	
	bool runMenu();
	void initButtons();
	void setPlay(bool newPlay);
	
	bool returnPlayTrue();
	bool manageScoreBoard();
	void printTopFiveScore(vector<string> scoreBoard);
	vector<string> formatScore(vector<string> scoreBoard);
	void sortScoreBoard(vector<string>& scoreBoardConetent);
	vector<string> readScoreBoard();


	



};

#endif