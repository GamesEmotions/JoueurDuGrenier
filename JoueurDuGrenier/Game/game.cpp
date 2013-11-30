#include "game.h"


Game* Game::_singleton = NULL;
sf::RenderWindow* Game::_frame = NULL;
bool Game::Running = false;

Game* Game::getInstance()
{
	return Game::_singleton;
}

Game* Game::newInstance(sf::RenderWindow* frame)
{
	if (Game::_singleton == NULL)
	{
		Game::_singleton = new Game(frame);
		return Game::_singleton;
	}
	return Game::_singleton;
}

Game::Game(sf::RenderWindow* frame)
{
	Game::_frame = frame;
	Game::Running = true;
}

Game::~Game()
{
}

void Game::Run()
{
	//New main menu
	Menu* mainMenu = new Menu();


	while (_frame->isOpen())
	{
		if (Game::Running)
		{
			_frame->clear();
			_frame->draw(*mainMenu);
			_frame->display();
			sf::Event Event;
			while (_frame->pollEvent(Event))
			{
				if (Event.type == sf::Event::Closed)
				{
					delete mainMenu;
					_frame->close();
				}
			}
		}
	}
}

sf::RenderWindow* Game::getFrame()
{
	return Game::_frame;
}