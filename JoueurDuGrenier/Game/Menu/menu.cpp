#include "menu.h"


Menu::Menu()
{
	_baseFont = new sf::Font();
	try
	{
		if (!_baseFont->loadFromFile(*FilesManager::getInstance()->getFile("file:font:Pixelized.ttf")))
		{
			throw std::exception("sf::Font::loadFromFile : can't open file !", 5001);
		}
	}
	catch (const std::exception &e)
	{
		sf::err() << e.what() << std::endl;
		exit(5001);
	}

	_title = new Title("Joueur du Grenier", _baseFont, 48, 40.f, 20.f);

	_background = new sf::Sprite(*ImagesManager::getInstance()->getTexture("image:background:background1"));
	_background->setScale(Game::getFrame()->getSize().x / _background->getLocalBounds().width, Game::getFrame()->getSize().y / _background->getLocalBounds().height);

	_music = SoundsManager::getInstance()->getMusic("sound:music:OpeningNight");
	_music->play();
	_music->setLoop(true);
}

Menu::~Menu()
{
	delete _title;
	delete _background;
	delete _baseFont;
}

void Menu::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(*_title, states);
	target.draw(*_background, states);
}

const sf::String* Menu::getTitle() const
{
	return _title->getString();
}

void Menu::setTitle(std::string newTitle)
{
	_title->setString(newTitle);
}

void Menu::setTitle(sf::String newTitle)
{
	_title->setString(newTitle);
}

const sf::Font* Menu::getFont() const
{
	return _title->getFont();
}

void Menu::setFont(sf::Font* baseFont)
{
	_baseFont = baseFont;
	_title->setFont(_baseFont);
}

const sf::Texture* Menu::getBackground() const
{
	return _background->getTexture();
}

void Menu::setBackground(sf::Texture* newBackground)
{
	_background->setTexture(*newBackground);
}

sf::Music* Menu::getMusic() const
{
	return _music;
}

void Menu::setMusic(sf::Music* newMusic)
{
	if (_music->Playing)
	{
		_music->stop();
	}
	_music = newMusic;
}

bool Menu::childPauseMusic() const
{
	return _childPauseMusic;
}

void Menu::childPauseMusic(bool doPause)
{
	_childPauseMusic = doPause;
	if (doPause == true)
	{
		_music->pause();
	}
	else
	{
		if (_music->getStatus() == sf::Music::Status::Paused)
		{
			_music->play();
		}
	}
}