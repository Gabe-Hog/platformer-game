#include "Game.h"
#include "MainMenu.h"
#include "Platform.h"
#include "Character.h"
#include "Timer.h"

#include <iostream>




Game::Game() : window(sf::VideoMode(WIDTH, HEIGHT), "test")
{
	window.setFramerateLimit(60);

}

Game::~Game()
{
	for (int i = 0; i < this->objects.size(); i++)
	{
		delete this->objects[i];
	}
	

}



void Game::eventHandle()
{
	sf::Event e;
	while (this->window.pollEvent(e))
	{
		if (e.type == sf::Event::Closed)
			this->window.close();
	}
}

void Game::update(float dTime)
{
	for (size_t i = 0; i < objects.size(); i++)
	{
		Character* pCharacter = dynamic_cast<Character*>(this->objects[i]);
		if (pCharacter != nullptr)
		{
			pCharacter->updatePosition(dTime);

		}
	}

	for (size_t i = 0; i < objects.size(); i++)
	{
		for (size_t j = 0; j < objects.size(); j++)
		{
			if (this->objects[i] != this->objects[j])

				this->objects[i]->checkCollision(*this->objects[j]);
		}
	}


}

void Game::render()
{
	this->window.clear();
	
	for (int i = 0; i < objects.size(); i++)
	{
		this->window.draw(*this->objects[i]);
	}
	this->window.display();
}

void Game::initGameObjects()
{
	Player* yourPlayer = new Player(&Game::endRound,this);


	this->addObject(yourPlayer);
	this->addObject(new Monster(*yourPlayer, updatePlayersScore));
	this->addObject(new Platform(sf::Vector2f(100, 500), sf::Color::Green, 200.f, 20.f));
	this->addObject(new Platform(sf::Vector2f(400, 400), sf::Color::Yellow, 100.f, 20.f));
	this->addObject(new Platform(sf::Vector2f(150, 250), sf::Color::Yellow, 150.f, 20.f));
	this->addObject(new Platform(sf::Vector2f(450, 170), sf::Color::Blue, 70.f, 20.f));
	
}



void Game::run()
{
	MainMenu menu(this->window);
	if (!menu.runMenu())
	{
		return;
	}
	roundEnded = false;
	initGameObjects();

	while (this->window.isOpen())
	{
		if (roundEnded)
			break;
		this->timer.setDeltaTime();
		float dTime = this->timer.getDeltaTime();

		eventHandle();
		update(dTime);
		render();
		
		
		this->timer.addToElapsedTime(this->timer.getClock()->getElapsedTime().asSeconds());
	}
	run();
}

bool Game::addObject(GameObjects* aObject)
{
	bool didAdd = false;
	if (aObject != nullptr)
	{
		this->objects.push_back(aObject);
		didAdd = true;
	}
	return didAdd;	
}

void Game::updateObjectPosition(float dTime)
{

	for (size_t i = 0; i < objects.size(); i++)
	{
		Character* pCharacter = dynamic_cast<Character*>(this->objects[i]);
		if (pCharacter != nullptr)
		{
			pCharacter->updatePosition(dTime);
		}
	}


}

void Game::makeCollisionCheck()
{
	for (size_t i = 0; i < objects.size(); i++)
	{
		for (size_t j = 0; j < objects.size(); j++)
		{
			if (this->objects[i] != this->objects[j])

				this->objects[i]->checkCollision(*this->objects[j]);
		}
	}
}

void Game::updatePlayersScore(const Player& player)
{
	Player& notConstPlayer = const_cast<Player&>(player);
	notConstPlayer.updateScore();


}




void Game::endRound(const Player& player)
{
	string playerStats = player.getStats() + " " + to_string(this->timer.getTimerElapsedTime());
	cout << playerStats << endl;
	this->writeScoreToFile(playerStats);
	for (auto& object : objects)
		{delete object;}
	this->objects.clear();
	this->roundEnded = true;
	
}

void Game::writeScoreToFile(string score)
{
	ofstream outPut("scoreBoard.txt", ios::app);
	if (!outPut.is_open())
	{
		throw("Error::Could Not Open File::");
	}
	outPut << score << endl;;
	outPut.close();
}



void Game::startMainMenu()
{


}


