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
	sf::Sprite mainMenuBackground;
	sf::Texture mainMenuBackgroundTexture;
	sf::Vector2f mouseCursorPosition;
	sf::Font textFont;
	sf::Text text;
	sf::Text scoreBoardText;
	assetHandler<sf::Font>* fontHandler;
	assetHandler<sf::Texture>* textureHandler;
	vector<unique_ptr<Button>> menuButtons;
	


	
	bool play = false;
	bool programClose= false;

	void displayMenu();
	void initBackground();
	void initText();
	void initButtons();
	void setPlay(bool newPlay);

	bool returnPlayTrue();
	bool manageScoreBoard();
	bool closeProgram();

	vector<string> readScoreBoard();
	void printTopFiveScore(vector<string> scoreBoard);
	vector<string> formatScore(vector<string> scoreBoard);
	static bool sortScoreBoard(const string& toComapreOne, const string& toComapreTwo);

	
	


public:

	MainMenu() = default;
	MainMenu(sf::RenderWindow& window, assetHandler<sf::Font>* fontHandler, assetHandler<sf::Texture>* textureHandler, string infoText = "-The Revenge Of The Chick-");
	~MainMenu();
	
	bool runMenu();

};

#endif