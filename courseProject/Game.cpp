#include "Game.h"
#include "MainMenu.h"
#include "Platform.h"
#include "Character.h"
#include "Timer.h"
#include <iostream>




Game::Game() : window(sf::VideoMode(WIDTH, HEIGHT), "Revenge Of The Chick")
{
	window.setFramerateLimit(60);
	
	try
	{
		this->fontHandler->addAsset("menuFont", "fonts/Branda-yolq.ttf");
		this->fontHandler->addAsset("nameFont", "fonts/MouldyCheeseRegular.ttf");
		this->textureHandler->addAsset("chick", "textures/chicken.png");
		this->textureHandler->addAsset("sword", "textures/chickStick.png");
		this->textureHandler->addAsset("enemyOven", "textures/evilOven1.png");
		this->textureHandler->addAsset("mainMenuBackground", "textures/mainMenuBackGround.jpg");
	}
	catch(runtime_error e)
	{
		cout << e.what() << endl;
	}

}

Game::Game(const Game& other) :
	timer(other.timer), fontHandler(new assetHandler<sf::Font>(*other.fontHandler)),
	textureHandler(new assetHandler<sf::Texture>(*other.textureHandler)), roundEnded(other.roundEnded)
{
	for(int i = 0; other.objects.size(); i++)
	{
		objects.push_back(objects[i]->clone());
	}

}

Game::~Game()
{
	for (int i = 0; i < this->objects.size(); i++)
	{
		delete this->objects[i];
	}

	delete this->textureHandler;
	delete this->fontHandler;

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


	this->updateObjectPosition(dTime);
	this->makeCollisionCheck();

}


void Game::run()
{
	MainMenu menu(this->window, this->fontHandler, this->textureHandler);

	if (!menu.runMenu())
	{
		return;
	}
	this->prepareGame();
	

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
	if(this->roundEnded)
		run();
}

void Game::render()
{
	this->window.clear();
	this->window.draw(this->windowBackground);
	for (int i = 0; i < objects.size(); i++)
	{
		this->window.draw(*this->objects[i]);

	}
	this->window.display();
}

void Game::initGameObjects()
{
	
	Player* yourPlayer = new Player(this, &Game::endRound, this->fontHandler, this->textureHandler);


	this->addObject(yourPlayer);
	this->addObject(new Enemy(*yourPlayer, this, &Game::updatePlayersScore, this->fontHandler, this->textureHandler));
	
	
	
	this->addObject(new Platform(sf::Vector2f(100, 500), 200.f, 20.f));
	this->addObject(new Platform(sf::Vector2f(400, 400), 100.f, 20.f));
	this->addObject(new Platform(sf::Vector2f(150, 250), 150.f, 20.f));
	this->addObject(new Platform(sf::Vector2f(450, 170), 70.f, 20.f));
	this->addObject(new Platform(sf::Vector2f(0, HEIGHT - 1.f), sf::Color::Transparent, WIDTH, 1.f));

}

void Game::initBackground()
{
	try
	{
		this->windowBackgroundTexture = this->textureHandler->getAsset("gameBackground");
		this->windowBackground.setTexture(this->windowBackgroundTexture);
	}

	catch (out_of_range e)
	{
		cout << e.what() << endl;
	}
}

void Game::prepareGame()
{
	initGameObjects();

	this->timer.getClock()->restart();
	this->roundEnded = false;
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
			pCharacter->checkForDeath();
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
	
	try
	{
		this->writeScoreToFile(playerStats);
	}
	catch (runtime_error e)
	{
		cout << e.what() << endl;
	}
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
		throw runtime_error("Error::Could Not Open File::");
	}
	outPut << score << endl;;
	outPut.close();
}





