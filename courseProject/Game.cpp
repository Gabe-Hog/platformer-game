#include "Game.h"
#include "Platform.h"
#include "Character.h"

void Game::eventHandle()
{
	sf::Event e;
	while (this->window.pollEvent(e))
	{
		if (e.type == sf::Event::Closed)
			this->window.close();
	}
}

void Game::update()
{
	for (size_t i = 0; i < objects.size(); i++)
	{
		Character* pCharacter = dynamic_cast<Character*>(this->objects[i]);
		if (pCharacter != nullptr)
		{
			pCharacter->updatePosition();
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
	this->addObject(new Platform(WIDTH, HEIGHT, sf::Color::Green, 80.f, 20.f));
	this->addObject(new Platform(WIDTH-200, HEIGHT-100, sf::Color::Yellow, 100.f, 30.f));
	this->addObject(new Platform(WIDTH-50, HEIGHT+100, sf::Color::Blue, 200.f, 20.f));
	this->addObject(new Player());
	this->addObject(new Monster());
}

Game::~Game()
{
}

void Game::run()
{
	while (this->window.isOpen())
	{
		eventHandle();
		update();
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


