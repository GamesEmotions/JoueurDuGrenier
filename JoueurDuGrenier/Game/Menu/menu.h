#ifndef INCLUDE_MENU
#define INCLUDE_MENU

//Error codes start by 5000

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include "../../JdgExceptions.h"
#include "../time.h"
#include "../game.h"
#include "drawable.h"


class Menu : public sf::Drawable
{
	public:
		Menu();
		Menu(Menu* parent);
		~Menu();

		const sf::String* getTitle() const;
		void setTitle(std::string newTitle);
		void setTitle(sf::String newTitle);
		const sf::Font* getFont() const;
		void setFont(sf::Font* baseFont);
		const sf::Texture* getBackground() const;
		void setBackground(sf::Texture* newBackground);
		sf::Music* getMusic() const;
		void setMusic(sf::Music* newMusic);
		bool childPauseMusic() const;
		void childPauseMusic(bool doPause);

		const Menu* _parent;

	private:
		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

		Title* _title;
		sf::Font* _baseFont;
		sf::Sprite* _background;
		sf::Music* _music;
		bool _childPauseMusic;
};

#endif