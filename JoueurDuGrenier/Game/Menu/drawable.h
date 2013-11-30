#ifndef INCLUDE_DRAWABLE
#define INCLUDE_DRAWABLE

//Error codes start by 7000

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Transformable.hpp>


class Title : public sf::Drawable, sf::Transformable
{
public:
	Title();
	Title(std::string title, sf::Font* font, unsigned int size, float x, float y);
	~Title();

	const sf::String* getString() const;
	void setString(std::string title);
	const sf::Font* getFont() const;
	void setFont(sf::Font* font);
	const unsigned int getCharacterSize() const;
	void setCharacterSize(unsigned int size);
	void setPosition(float x, float y);

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	sf::Text* _title_upper;
	sf::Text* _title_under;
};

#endif