#include "game.h"

Game::Game() : _window(sf::VideoMode(640,480), "Joueur du Grenier"), _texture(), _player()
{
	ResourceHolder* resourceHolder = ResourceHolder::getInstance();
	_texture = resourceHolder->getEntity(Entities::Player);
	_isMovingDown = false;
	_isMovingLeft = false;
	_isMovingRight = false;
	_isMovingUp = false;
	_player.setTexture(_texture);
	_player.setPosition(100.f, 100.f);
}

void Game::run()
{
	const sf::Time TIMEPERFRAME = sf::seconds(1.f / 60.f);
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (_window.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TIMEPERFRAME)
		{
			timeSinceLastUpdate -= TIMEPERFRAME;
			processEvents();
			update(TIMEPERFRAME);
		}
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (_window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			handlePlayerInput(event.key.code, true);
			break;
		case sf::Event::KeyReleased:
			handlePlayerInput(event.key.code, false);
			break;
		case sf::Event::Closed:
			_window.close();
			break;
		}
	}
}

void Game::update(sf::Time dt)
{
	sf::Vector2f movement(0.f, 0.f);
	if (_isMovingUp)
	{
		movement.y -= 50.f;
	}
	if (_isMovingDown)
	{
		movement.y += 50.f;
	}
	if (_isMovingLeft)
	{
		movement.x -= 50.f;
	}
	if (_isMovingRight)
	{
		movement.x += 50.f;
	}

	_player.move(movement * dt.asSeconds());
}

void Game::render()
{
	_window.clear();
	_window.draw(_player);
	_window.display();
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
	if (key == sf::Keyboard::Z)
	{
		_isMovingUp = isPressed;
	}
	else if (key == sf::Keyboard::Q)
	{
		_isMovingLeft = isPressed;
	}
	else if (key == sf::Keyboard::S)
	{
		_isMovingDown = isPressed;
	}
	else if (key == sf::Keyboard::D)
	{
		_isMovingRight = isPressed;
	}
}