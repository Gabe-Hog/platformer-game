#include "Game.h"

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
}

Game::Game() : window(sf::VideoMode(800, 800), "test")
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

	}
}

bool Game::addObject()
{
	return false;
}


