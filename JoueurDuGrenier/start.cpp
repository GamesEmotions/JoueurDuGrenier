
//Error codes start by 0000

#include "Game/game.h"


int main(int argc, char** argv) {
	sf::RenderWindow frame(sf::VideoMode(960, 540), "Joueur du grenier");
	Game* instance = Game::newInstance(&frame);
	instance->Run();

	/*sf::Sprite sprite(*imagesManager->getImage(0));
	sprite.setPosition(0.f, 150.f);
	sf::Sprite sprite2(*imagesManager->getImage(1));
	sprite2.setPosition(0.f, 100.f);
	sf::Sprite sprite4(*imagesManager->getImage(1));
	sprite4.setPosition(50.f, 100.f);
	sf::Sprite sprite3(*imagesManager->getImage(2));
	sprite3.setPosition(0.f, 200.f);

	sf::Music *menuMusic = soundsManager->getMusic(3);
	menuMusic->play();
	menuMusic->setLoop(true);

	sf::Font baseFont;
	try{
		if (!baseFont.loadFromFile(*filesManager->getFile("file:font:Pixelized.ttf")))
		{
			exit(0002);
		}
	}
	catch(const std::exception &e)
	{
		sf::err() << e.what() << std::endl;
		exit(0003);
	}

	sf::Text title1;
	title1.setFont(baseFont);
	title1.setString("Joueur du Grenier");
	title1.setCharacterSize(48);
	title1.setPosition(40.f, 10.f);
	title1.setColor(sf::Color::Yellow);

	sf::Text title2;
	title2.setFont(baseFont);
	title2.setString("Joueur du Grenier");
	title2.setCharacterSize(48);
	title2.setPosition(40.f + 2.f, 10.f + 4.f);
	title2.setColor(sf::Color::Blue);

	while (Frame.isOpen())
	{
		sf::Event Event;
		while (Frame.pollEvent(Event))
		{
			if (Event.type == sf::Event::Closed)
			{
				imagesManager->kill();
				soundsManager->kill();
				filesManager->kill();
				Frame.close();
			}

			Frame.clear();
			//draw
			Frame.draw(sprite);
			Frame.draw(sprite2);
			Frame.draw(sprite3);
			Frame.draw(sprite4);
			Frame.draw(title2);
			Frame.draw(title1);
			Frame.display();
		}
	}*/
	return 0;
}