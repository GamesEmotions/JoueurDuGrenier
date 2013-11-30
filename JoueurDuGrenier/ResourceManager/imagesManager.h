#ifndef INCLUDE_IMAGESMANAGER
#define INCLUDE_IMAGESMANAGER

//Error codes start by 2000

#include "dirent.h"
#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include <string.h>
#include <unordered_map>
#include "../JdgExceptions.h"


class ImagesManager
{
	private:
		static ImagesManager* _singleton;
		std::unordered_map<int, sf::Texture> _texturesArray;
		std::unordered_map<std::string, sf::Texture*> _texturesNamesToIDs;

		ImagesManager();
		~ImagesManager();

	public:
		const sf::Texture* getTexture(int textureID) const;
		const sf::Texture* getTexture(std::string textureName) const;
		static ImagesManager* getInstance();
		static void kill();
};

#endif