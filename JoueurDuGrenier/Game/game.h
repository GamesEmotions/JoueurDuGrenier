#ifndef INCLUDE_GAME
#define INCLUDE_GAME

//Error codes start by 6000

#include <SFML/Graphics.hpp>
#include "../ResourceManager/imagesManager.h"
#include "../ResourceManager/soundsManager.h"
#include "../ResourceManager/filesManager.h"
#include "Menu/menu.h"


static class Game
{
private:
	Game(sf::RenderWindow* frame);
	~Game();
	static Game* _singleton;
	static sf::RenderWindow* _frame;

public:
	static Game* getInstance();
	static Game* newInstance(sf::RenderWindow* frame);
	static sf::RenderWindow* getFrame();
	static void Run();

	static bool Running;
};

#endif