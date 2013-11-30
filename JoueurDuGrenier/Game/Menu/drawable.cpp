#include "drawable.h"


Title::Title()
{
	_title_under = new sf::Text();
	_title_upper = new sf::Text();
}

Title::Title(std::string title, sf::Font* font, unsigned int size, float x, float y)
{
	_title_under = new sf::Text();
	_title_upper = new sf::Text();
	_title_under->setString(title);
	_title_upper->setString(title);
	_title_under->setFont(*font);
	_title_upper->setFont(*font);
	_title_under->setColor(sf::Color::Blue);
	_title_upper->setColor(sf::Color::Yellow);
	_title_under->setCharacterSize(size);
	_title_upper->setCharacterSize(size);
	_title_under->setPosition(x, y);
	_title_upper->setPosition(x, y);
}

Title::~Title()
{
	delete _title_under;
	delete _title_upper;
}

void Title::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*_title_under, states);
	target.draw(*_title_upper, states);
}

const sf::String* Title::getString() const
{
	return &_title_under->getString();
}

void Title::setString(std::string title)
{
	_title_under->setString(title);
	_title_upper->setString(title);
}

const sf::Font* Title::getFont() const
{
	return _title_under->getFont();
}

void Title::setFont(sf::Font* font)
{
	_title_under->setFont(*font);
	_title_upper->setFont(*font);
}

const unsigned int Title::getCharacterSize() const
{
	return _title_under->getCharacterSize();
}

void Title::setPosition(float x, float y)
{
	_title_under->setPosition(x, y);
	_title_upper->setPosition(x, y);
}
