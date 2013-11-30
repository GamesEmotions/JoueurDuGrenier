#ifndef INCLUDE_TILE
#define INCLUDE_TILE

#include <SFML/Graphics.hpp>
#include "../time.h"


class Tile : sf::Drawable
{
public:
	Tile();
	Tile(sf::Texture* texture, float x, float y);
	Tile(sf::Texture* texture, sf::Vector2<float> position);
	~Tile();
	void setPosition(float x, float y);
	void setPosition(sf::Vector2<float> position);
	sf::Vector2<float> getPosition() const;
	void setTexture(sf::Texture* texture);
	const sf::Texture* getTexture() const;

protected:
	sf::Sprite* _sprite;

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};


class AnimatedTile : Tile, Listener
{
public:
	AnimatedTile();
	AnimatedTile(std::vector<sf::Texture*> textures, float x, float y, Notifier* notifier);
	AnimatedTile(std::vector<sf::Texture*> textures, sf::Vector2<float> position, Notifier* notifier);
	void setTextures(std::vector<sf::Texture*> textures);
	const std::vector<sf::Texture*> getTextures() const;
	virtual void getNotification(const Notifier* notifier);

protected:
	std::vector<sf::Texture*> _textures;
	int _pos;

private:
	void setTexture(sf::Texture* texture);
	const sf::Texture* getTexture() const;
};

class MonoAnimationTile : Tile, AnimatedTile, Listener
{
public:
	MonoAnimationTile();
	MonoAnimationTile(std::vector<sf::Texture*> textures, float x, float y, Notifier* frameNotifier, Notifier* startAnimation);
	MonoAnimationTile(std::vector<sf::Texture*> textures, sf::Vector2<float> pos, Notifier* frameNotifier, Notifier* startAnimation);
	virtual void getNotification(const Notifier* notifier);

private:
	bool _run;
};

#endif