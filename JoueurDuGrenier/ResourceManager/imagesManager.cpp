#include "imagesManager.h"


ImagesManager *ImagesManager::_singleton = NULL;

ImagesManager::ImagesManager()
{
	DIR* texturesDir = NULL;
	struct dirent* file = NULL;
	std::string extension = ".png";
	std::string prefix = "image:tile:";
	std::string path = "./resources/images/tiles/";

	texturesDir = opendir("./resources/images/tiles");
	
	if (texturesDir == NULL)
	{
		throw ManagerException(2001, "Unable to open directory\n\terrno: " + errno);
	}

	int i=0;
	while ((file = readdir(texturesDir)) != NULL)
	{
		if (file->d_type == DT_REG)
		{
			std::string filename = file->d_name;
			if (filename.find(extension, (filename.length() - extension.length())) != std::string::npos)
			{
				_texturesArray[i] = sf::Texture();
				_texturesArray[i].loadFromFile(path + file->d_name);
				_texturesArray[i].setSmooth(false);
				_texturesNamesToIDs[prefix + file->d_name] = &_texturesArray[i];
				i++;
			}
		}
	}

	if (closedir(texturesDir) == -1)
	{
		throw ManagerException(2002, "Error when closing directory\n\terrno: " + errno);
	}

	DIR* imagesDir = NULL;
	file = NULL;
	extension = ".png";
	prefix = "image:background:";
	path = "./resources/images/backgrounds/";

	imagesDir = opendir("./resources/images/backgrounds");
	
	if (imagesDir == NULL)
	{
		throw ManagerException(2006, "Unable to open directory\n\terrno: " + errno);
	}

	i=1000;
	while ((file = readdir(imagesDir)) != NULL)
	{
		if (file->d_type == DT_REG)
		{
			std::string filename = file->d_name;
			if (filename.find(extension, (filename.length() - extension.length())) != std::string::npos)
			{
				sf::Texture *temp = new sf::Texture;
				temp->loadFromFile(path + file->d_name);
				_texturesArray[i] = sf::Texture();
				_texturesArray[i].loadFromFile(path + file->d_name);
				_texturesNamesToIDs[prefix + file->d_name] = &_texturesArray[i];
				i++;
			}
		}
	}

	if (closedir(imagesDir) == -1)
	{
		throw ManagerException(2008, "Error when closing directory\n\terrno: " + errno);
	}
}

ImagesManager::~ImagesManager()
{
	int capacity = _texturesArray.size();
	for (int i = 0; i < capacity; i++)
	{
		delete &_texturesArray[i];
	}
	_texturesArray.clear();
	_texturesNamesToIDs.clear();
}

const sf::Texture* ImagesManager::getTexture(int textureID) const
{
	if (_texturesArray.find(textureID) != _texturesArray.end())
	{
		return &_texturesArray.at(textureID);
	}
	throw ManagerException(2008, "Bad ID: " + textureID);
}

const sf::Texture* ImagesManager::getTexture(std::string textureName) const
{
	textureName += ".png";
	if (_texturesNamesToIDs.find(textureName) != _texturesNamesToIDs.end())
	{
		return _texturesNamesToIDs.at(textureName);
	}
	throw ManagerException(2009, "Bad name: " + textureName);
}

ImagesManager* ImagesManager::getInstance()
{
	if (_singleton == NULL)
	{
		try
		{
			_singleton = new ImagesManager;
		}
		catch(const std::exception &e)
		{
			sf::err() << e.what() << std::endl;
			exit(2005);
		}
	}
	return _singleton;
}

void ImagesManager::kill()
{
	delete _singleton;
	_singleton = NULL;
}
