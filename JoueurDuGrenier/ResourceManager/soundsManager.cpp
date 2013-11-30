#include "soundsManager.h"


SoundsManager *SoundsManager::_singleton = NULL;

SoundsManager::SoundsManager()
{
	DIR* musicsDir = NULL;
	struct dirent* file = NULL;
	std::string extension = ".flac";
	std::string prefix = "sound:music:";
	std::string path = "./resources/sounds/musics/";

	musicsDir = opendir("./resources/sounds/musics");
	
	if (musicsDir == NULL)
	{
		throw ManagerException(3001, "Unable to open directory\n\terrno: " + errno);
	}

	int i=0;
	while ((file = readdir(musicsDir)) != NULL)
	{
		if (file->d_type == DT_REG)
		{
			std::string filename = file->d_name;
			if (filename.find(extension, (filename.length() - extension.length())) != std::string::npos)
			{
				_musicsArray[i] = new sf::Music();
				_musicsArray[i]->openFromFile(path + file->d_name);
				_musicsNamesToIDs[prefix + file->d_name] = _musicsArray[i];
				i++;
			}
		}
	}

	if (closedir(musicsDir) == -1)
	{
		throw ManagerException(3002, "Error when closing directory\n\terrno: " + errno);
	}


	DIR* loopsDir = NULL;
	file = NULL;
	extension = ".ogg";
	prefix = "sound:loop:";
	path = "./resources/sounds/loops/";

	loopsDir = opendir("./resources/sounds/loops");
	
	if (loopsDir == NULL)
	{
		throw ManagerException(3006, "Unable to open directory\n\terrno: " + errno);
	}

	i=0;
	while ((file = readdir(loopsDir)) != NULL)
	{
		if (file->d_type == DT_REG)
		{
			std::string filename = file->d_name;
			if (filename.find(extension, (filename.length() - extension.length())) != std::string::npos)
			{
				_loopsArray[i] = new sf::SoundBuffer();
				_loopsArray[i]->loadFromFile(path + file->d_name);
				_loopsNamesToIDs[prefix + file->d_name] = _loopsArray[i];
				i++;
			}
		}
	}

	if (closedir(loopsDir) == -1)
	{
		throw ManagerException(3007, "Error when closing directory\n\terrno: " + errno);
	}
}

SoundsManager::~SoundsManager()
{
	int capacity = _musicsArray.size();
	for (int i = 0; i < capacity; i++)
	{
		delete &_musicsArray[i];
	}
	_musicsArray.clear();
	capacity = _loopsArray.size();
	for (int i = 0; i < capacity; i++)
	{
		delete &_loopsArray[i];
	}
	_loopsArray.clear();
}

sf::Music* SoundsManager::getMusic(int musicID) const
{
	if (_musicsArray.find(musicID) != _musicsArray.end())
	{
		return _musicsArray.at(musicID);
	}
	throw ManagerException(3003, "Bad ID: " + musicID);
}

sf::Music* SoundsManager::getMusic(std::string musicName) const
{
	musicName += ".flac";
	if (_musicsNamesToIDs.find(musicName) != _musicsNamesToIDs.end())
	{
		return _musicsNamesToIDs.at(musicName);
	}
	throw ManagerException(3004, "Bad name: " + musicName);
}

sf::SoundBuffer* SoundsManager::getLoop(int loopID) const
{
	if (_loopsArray.find(loopID) != _loopsArray.end())
	{
		return _loopsArray.at(loopID);
	}
	throw ManagerException(3008, "Bad ID: " + loopID);
}

sf::SoundBuffer* SoundsManager::getLoop(std::string loopName) const
{
	loopName += ".ogg";
	if (_loopsNamesToIDs.find(loopName) != _loopsNamesToIDs.end())
	{
		return _loopsNamesToIDs.at(loopName);
	}
	throw ManagerException(3009, "Bad name: " + loopName);
}

SoundsManager* SoundsManager::getInstance()
{
	if (SoundsManager::_singleton == NULL)
	{
		try
		{
			_singleton = new SoundsManager;
		}
		catch(const std::exception &e)
		{
			sf::err() << e.what() << std::endl;
			exit(3005);
		}
	}
	return _singleton;
}

void SoundsManager::kill()
{
	delete _singleton;
	_singleton = NULL;
}
