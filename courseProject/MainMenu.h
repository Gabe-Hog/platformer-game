#ifndef MAINMENU_H
#define MAINMENU_H
#include <fstream>
#include <vector>
#include <memory>
#include <string>
#include "SFML/Graphics.hpp"
#include "Button.h"

using namespace std;
class MainMenu
{

private:
	sf::RenderWindow& window;
	sf::Vector2f mouseCursorPosition;
	sf::Font textFont;
	sf::Text text;
	sf::Text scoreBoardText;
	vector<unique_ptr<Button>> menuButtons;
	
	bool play = false;

public:

	MainMenu() = default;
	MainMenu(sf::RenderWindow& window, string infoText = "Hello World!");
	void displayMenu();
	
	bool runMenu();
	void initButtons();
	void setPlay(bool newPlay);
	void readFont();
	bool returnPlayTrue();
	bool manageScoreBoard();
	void printTopFiveScore(vector<string> scoreBoard);
	vector<string> formatScore(vector<string> scoreBoard);
	void sortScoreBoard(vector<string>& scoreBoardConetent);
	vector<string> readScoreBoard();


	~MainMenu();



};

#endif