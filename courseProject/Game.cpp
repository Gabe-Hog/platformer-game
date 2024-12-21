#include "Game.h"
#include "Platform.h"
#include "Character.h"
#include "Timer.h"
#include <iostream>

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
			if(this->objects[i] != this->objects[j])

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

Game::Game() : window(sf::VideoMode(WIDTH, HEIGHT), "test")		
{  
	window.setFramerateLimit(60);
	Player* yourPlayer = new Player();
	this->addObject(new Platform(sf::Vector2f(100,500), sf::Color::Green, 200.f, 20.f));
	this->addObject(new Platform(sf::Vector2f(400, 400),  sf::Color::Yellow, 100.f, 20.f));
	this->addObject(new Platform(sf::Vector2f(150, 250),  sf::Color::Yellow, 150.f, 20.f));
	this->addObject(new Platform(sf::Vector2f(450, 170), sf::Color::Blue, 70.f, 20.f));
	this->addObject(yourPlayer);
	this->addObject(new Monster(yourPlayer));
}

Game::~Game()
{
	for (size_t i = 0; i < this->objects.size(); i++)
	{
		delete this->objects[i];
	}
}

void Game::run()
{

	while (this->window.isOpen())
	{
		this->clock.setDeltaTime();
		float dTime = this->clock.getDeltaTime();


		eventHandle();
		update(dTime);
		render();
		
		
		
	}
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


