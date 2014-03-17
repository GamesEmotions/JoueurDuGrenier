#ifndef INCLUDE_GAME
#define INCLUDE_GAME

//Error codes start by 6000

#include "SFML/Graphics.hpp"
#include "SFML/System/Time.hpp"
#include "../ResourceHolder/resourceHolder.h"


class Game
{
private:
	void processEvents();
		void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
			bool _isMovingUp;
			bool _isMovingLeft;
			bool _isMovingRight;
			bool _isMovingDown;
	void update(sf::Time dt);
	void render();

	sf::RenderWindow _window;
	sf::Texture _texture;
	sf::Sprite _player;

public:
	Game();
	void run();
};

#endif