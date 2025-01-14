#include "MainMenu.h"
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include "stdlib.h"
#include <iostream>


MainMenu::MainMenu(sf::RenderWindow& window, assetHandler<sf::Font>* fontHandler, assetHandler<sf::Texture>* textureHandler, string infoText) :
	window(window), fontHandler(fontHandler), textureHandler(textureHandler)
{
	this->textFont = fontHandler->getAsset("menuFont");
	this->text.setString(infoText);

	this->initBackground();
	this->initText();

	this->initButtons();
}

MainMenu::~MainMenu()
{

}

void MainMenu::displayMenu()
{
	this->window.clear();
	this->window.draw(this->mainMenuBackground);
	this->window.draw(text);
	this->window.draw(scoreBoardText);

	for (int i = 0; i < this->menuButtons.size(); i++)
	{
		this->window.draw(*this->menuButtons[i]);

	}
	this->window.display();
}

void MainMenu::initBackground()
{
	try 
	{
		this->mainMenuBackgroundTexture = this->textureHandler->getAsset("mainMenuBackground");
		this->mainMenuBackground.setTexture(mainMenuBackgroundTexture);
	}

	catch (out_of_range e)
	{
		cout << e.what() << endl;
	}
}

void MainMenu::initText()
{
	this->text.setCharacterSize(30);
	this->text.setFillColor(sf::Color::White);
	this->text.setFont(textFont);
	this->text.setPosition(this->window.getSize().x / 5.f, this->window.getSize().y / 3.f);

	this->scoreBoardText.setCharacterSize(20);
	this->scoreBoardText.setFont(this->textFont);
	this->scoreBoardText.setLetterSpacing(2);
	this->scoreBoardText.setPosition(this->window.getSize().x / 2.5f, this->window.getSize().y / 2.5f);
	this->scoreBoardText.setFillColor(sf::Color::White);
}





bool MainMenu::runMenu()
{
	while (!play && !programClose)
	{
		this->mouseCursorPosition = this->window.mapPixelToCoords(sf::Mouse::getPosition(this->window));
		displayMenu();
		sf::Event e;
		while (this->window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				return false;
		
			if(e.type == sf::Event::MouseButtonPressed)
			{
				for (int i = 0; i < menuButtons.size(); i++)
				{
					menuButtons[i]->checkForButtonPress(this->mouseCursorPosition, e);
				}
			}
		}
		for (auto& button : menuButtons)
			button->onHover(this->mouseCursorPosition);
	}

	return true;
}

void MainMenu::initButtons() 
{
	this->menuButtons.push_back(make_unique<Button>(&MainMenu::returnPlayTrue, *this, this->textFont,
		sf::Vector2f(this->window.getSize().x / 5.f, this->window.getSize().y / 2.5f), "Play Game"));
	this->menuButtons.push_back(make_unique<Button>(&MainMenu::manageScoreBoard, *this, this->textFont,
		sf::Vector2f(this->window.getSize().x / 5.f, this->window.getSize().y / 2.5f+ 30.f), "Show ScoreBoard"));
	this->menuButtons.push_back(make_unique<Button>(&MainMenu::closeProgram, *this, this->textFont,
		sf::Vector2f(this->window.getSize().x / 5.f, this->window.getSize().y / 2.5f+ 60.f), "Exit"));
}

void MainMenu::setPlay(bool newPlay)
{
	this->play = newPlay;
}


bool MainMenu::returnPlayTrue()
{
	this->play = true;
	return this->play;
}

bool MainMenu::manageScoreBoard()
{
	bool didPrintScoreBoard = false;
	try
	{
		vector<string> lines = readScoreBoard();
		sort(lines.begin(), lines.end(), sortScoreBoard);
		lines = formatScore(lines);
		printTopFiveScore(lines);
		didPrintScoreBoard = true;
	}
	catch (runtime_error e)
	{
		this->scoreBoardText.setString(e.what());
	}

	return didPrintScoreBoard;
}

bool MainMenu::closeProgram()
{
	this->programClose = true;
	this->window.close();
	return true;
}

void MainMenu::printTopFiveScore(vector<string> scoreBoard)
{
	string concat = "Top 5 scores\n";
	scoreBoard.resize(5);
	for (auto& line : scoreBoard)
	{
		concat += line + "\n";
	}
	this->scoreBoardText.setString(concat);
}

vector<string> MainMenu::formatScore(vector<string> scoreBoard)
{
	vector<string> formated;
	for (auto& line : scoreBoard)
	{
		istringstream splitStream(line);
		string name;
		int score;
		float time;
		splitStream >> name >> score >> time;
		formated.push_back("Name: " + name + " Score: " + to_string(score) + " Time: " + to_string(time) + " Seconds");
		
	}
	return formated;
}

bool MainMenu::sortScoreBoard(const string& toCompareOne, const string& toCompareTwo)
{
		istringstream splitStream(toCompareOne);
		istringstream splitStream2(toCompareTwo);

		string nameOne, nameTwo;
		int scoreOne, scoreTwo;
		float timeOne, timeTwo;


		splitStream >> nameOne >> scoreOne >> timeOne;
		splitStream2 >> nameTwo >> scoreTwo >> timeTwo;


		if (scoreOne == scoreTwo)
			return timeOne < timeTwo;
	
		return scoreOne > scoreTwo;
}


vector<string> MainMenu::readScoreBoard()
{
	bool didRead = false;
	string line;
	vector<string> lines;
	ifstream inPut("scoreBoard.txt");
	if (!inPut.is_open())
	{
		throw runtime_error("Error::Could Not Open File::");
	}
	while (getline(inPut, line))
	{
		
		lines.push_back(line);
	}
	inPut.close();
	return lines;

}


