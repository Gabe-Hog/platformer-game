#include "MainMenu.h"
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <algorithm>

MainMenu::MainMenu(sf::RenderWindow& window, string infoText) : window(window)
{
	
	this->readFont();
	this->text.setString(infoText);
	sf::FloatRect textBounds = this->text.getLocalBounds();
	this->text.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.f);
	this->text.setCharacterSize(30);
	this->text.setFillColor(sf::Color::Red);
	this->text.setFont(textFont);
	this->text.setPosition(this->window.getSize().x / 5.f, this->window.getSize().y / 3.f);
	this->scoreBoardText.setFont(textFont);
	this->scoreBoardText.setCharacterSize(20);
	this->scoreBoardText.setPosition(this->window.getSize().x/2.f, this->window.getSize().y / 3.f);
	this->scoreBoardText.setFillColor(sf::Color::White);
	this->initButtons();
	


}

void MainMenu::displayMenu()
{
	this->window.clear();
	this->window.draw(text);
	this->window.draw(scoreBoardText);
	for (int i = 0; i < this->menuButtons.size(); i++)
	{
		this->window.draw(*this->menuButtons[i]);

	}
	this->window.display();


}





bool MainMenu::runMenu()
{
	while (!play)
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

		

	}

	return true;

}

void MainMenu::initButtons() 
{
	this->menuButtons.push_back(make_unique<Button>(&MainMenu::returnPlayTrue, *this, this->textFont,
		sf::Vector2f(this->window.getSize().x / 5.f, this->window.getSize().y / 2.5f), "Play Game"));
	this->menuButtons.push_back(make_unique<Button>(&MainMenu::manageScoreBoard, *this, this->textFont,
		sf::Vector2f(this->window.getSize().x / 5.f, this->window.getSize().y / 2.5f+ 30.f), "Show ScoreBoard"));
	/*this->menuButtons.push_back(make_unique<Button>(&MainMenu::readScoreBoard, *this, this->textFont,
		sf::Vector2f(this->window.getSize().x / 5.f, this->window.getSize().y / 2.5f+ 60.f)));*/

}

void MainMenu::setPlay(bool newPlay)
{

	this->play = newPlay;
}

void MainMenu::readFont()
{
	if (!this->textFont.loadFromFile("fonts/Branda-yolq.ttf"))
	{
		throw("Error::Could Not Read Font::MainMenu.cpp");
	}
	
}

bool MainMenu::returnPlayTrue()
{
	this->play = true;
	return this->play;
}

bool MainMenu::manageScoreBoard()
{
	vector<string> lines = readScoreBoard();
	sortScoreBoard(lines);
	lines = formatScore(lines);
	printTopFiveScore(lines);

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

void MainMenu::sortScoreBoard(vector<string>& scoreBoardContent)
{
	
	

	for (int i = 0; i < scoreBoardContent.size(); i++)
	{

		istringstream splitStream(scoreBoardContent[i]);
		string name;
		int score;
		float time;
		splitStream >> name >> score >> time;
		for (int j = 0; j < scoreBoardContent.size(); j++)
		{
			istringstream splitStream2(scoreBoardContent[j]);
			string name2;
			int score2;
			float time2;
			splitStream2 >> name2 >> score2 >> time2;
			string temp;
			if (score > score2 || (score == score2 && time < time2)) 
			{ std::swap(scoreBoardContent[i], scoreBoardContent[j]); }
		}

	}
	

}


vector<string> MainMenu::readScoreBoard()
{
	bool didRead = false;
	string line;
	vector<string> lines;
	ifstream inPut("scoreBoard.txt");
	if (!inPut.is_open())
	{
		throw("Error::Could Not Open File::");
	}
	while (getline(inPut, line))
	{
		
		lines.push_back(line);
	}
	inPut.close();
	return lines;

}

MainMenu::~MainMenu()
{

}
