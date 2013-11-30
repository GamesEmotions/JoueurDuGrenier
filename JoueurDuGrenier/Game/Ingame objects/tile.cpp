#include "tile.h"


Tile::Tile()
{
	_sprite = new sf::Sprite();
}

Tile::Tile(sf::Texture* texture, float x, float y)
{
	_sprite = new sf::Sprite(*texture);
	_sprite->setPosition(x, y);
}

Tile::Tile(sf::Texture* texture, sf::Vector2<float> position)
{
	_sprite = new sf::Sprite(*texture);
	_sprite->setPosition(position);
}

Tile::~Tile()
{
	delete _sprite;
}

void Tile::setPosition(float x, float y)
{
	_sprite->setPosition(x, y);
}

void Tile::setPosition(sf::Vector2<float> position)
{
	_sprite->setPosition(position);
}

sf::Vector2<float> Tile::getPosition() const
{
	return _sprite->getPosition();
}

void Tile::setTexture(sf::Texture* texture)
{
	_sprite->setTexture(*texture);
}

const sf::Texture* Tile::getTexture() const
{
	return _sprite->getTexture();
}

void Tile::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*_sprite, states);
}



AnimatedTile::AnimatedTile(std::vector<sf::Texture*> textures, float x, float y, Notifier* notifier)
{
	try
	{
		_sprite->setTexture(*textures.at(0));
	}
	catch (const std::exception &e)
	{
		sf::err() << e.what() << std::endl;
	}

	_pos = 0;
	_sprite->setPosition(x, y);
	_textures = textures;
	notifier->RegisterListener(this);
}

AnimatedTile::AnimatedTile(std::vector<sf::Texture*> textures, sf::Vector2<float> pos, Notifier* notifier)
{
	try
	{
		_sprite->setTexture(*textures.at(0));
	}
	catch (const std::exception &e)
	{
		sf::err() << e.what() << std::endl;
	}

	_pos = 0;
	_sprite->setPosition(pos);
	_textures = textures;
	notifier->RegisterListener(this);
}

void AnimatedTile::setTextures(std::vector<sf::Texture*> textures)
{
	_textures = textures;
	try
	{
		_sprite->setTexture(*_textures.at(0));
	}
	catch (const std::exception &e)
	{
		sf::err() << e.what() << std::endl;
	}
	_pos = 0;
}

const std::vector<sf::Texture*> AnimatedTile::getTextures() const
{
	return _textures;
}

void AnimatedTile::getNotification(const Notifier*)
{
	_pos++;
	if (_pos >= _textures.size())
	{
		_pos = 0;
	}
	_sprite->setTexture(*_textures.at(_pos));
}



MonoAnimationTile::MonoAnimationTile(std::vector<sf::Texture*> textures, float x, float y, Notifier* frameNotifier, Notifier* start)
{
	AnimatedTile(textures, x, y, frameNotifier);
	_run = false;
	start->RegisterListener(this);
}

MonoAnimationTile::MonoAnimationTile(std::vector<sf::Texture*> textures, sf::Vector2<float> pos, Notifier* frameNotifier, Notifier* start)
{
	AnimatedTile(textures, pos, frameNotifier);
	_run = false;
	start->RegisterListener(this);
}

void MonoAnimationTile::getNotification(const Notifier* notifier)
{
	if (_run)
	{
		AnimatedTile::getNotification(notifier);
	}
}