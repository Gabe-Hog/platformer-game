#include "Game.h"
#include "Platform.h"
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
	
}

void Game::render()
{
	this->window.clear();
	this->window.draw(this->platform);
	this->window.display();
}

Game::Game() : window(sf::VideoMode(WIDTH, HEIGHT), "test"),
				platform(WIDTH, HEIGHT, sf::Color::Green, 80.f, 20.f)
{
}

Game::~Game()
{
}

void Game::run()
{
	while (this->window.isOpen())
	{
		eventHandle();
		render();

	}
}

bool Game::addObject()
{
	return false;
}


