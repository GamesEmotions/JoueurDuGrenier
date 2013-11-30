#ifndef INCLUDE_MUSICSMANAGER
#define INCLUDE_MUSICSMANAGER

//Error codes start by 3000

#include "dirent.h"
#include <stdio.h>
#include <stdlib.h>
#include <SFML/Audio.hpp>
#include <string.h>
#include <unordered_map>
#include "../JdgExceptions.h"


class SoundsManager
{
	private:
		static SoundsManager* _singleton;
		std::unordered_map<int, sf::Music*> _musicsArray;
		std::unordered_map<std::string, sf::Music*> _musicsNamesToIDs;
		std::unordered_map<int, sf::SoundBuffer*> _loopsArray;
		std::unordered_map<std::string, sf::SoundBuffer*> _loopsNamesToIDs;

		SoundsManager();
		~SoundsManager();

	public:
		sf::Music* getMusic(int musicID) const;
		sf::Music* getMusic(std::string musicName) const;
		sf::SoundBuffer* getLoop(int loopID) const;
		sf::SoundBuffer* getLoop(std::string loopName) const;
		static SoundsManager* getInstance();
		static void kill();
};

#endif