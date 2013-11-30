#include "filesManager.h"


FilesManager *FilesManager::_singleton = NULL;

FilesManager::FilesManager()
{
	DIR* filesDir = NULL;
	struct dirent* file = NULL;
	std::string extension = ".conf";
	std::string prefix = "file:conf:";
	std::string path = "./resources/misc/config/";

	filesDir = opendir("./resources/misc/config");
	
	if (filesDir == NULL)
	{
		throw ManagerException(1001, "Unable to open directory\n\terrno: " + errno);
	}

	int i=0;
	while ((file = readdir(filesDir)) != NULL)
	{
		if (file->d_type == DT_REG)
		{
			std::string filename = file->d_name;
			if (filename.find(extension, (filename.length() - extension.length())) != std::string::npos)
			{
				_filesArray[i] = new std::string(path + file->d_name);
				_filesNamesToIDs[prefix + file->d_name] = _filesArray[i];
				i++;
			}
		}
	}

	if (closedir(filesDir) == -1)
	{
		throw ManagerException(1002, "Error when closing directory\n\terrno: " + errno);
	}


	filesDir = NULL;
	file = NULL;
	extension = ".ttf";
	prefix = "file:font:";
	path = "./resources/misc/font/";

	filesDir = opendir("./resources/misc/font");
	
	if (filesDir == NULL)
	{
		throw ManagerException(1003, "Unable to open directory\n\terrno: " + errno);
	}

	i = 1000;
	while ((file = readdir(filesDir)) != NULL)
	{
		if (file->d_type == DT_REG)
		{
			std::string filename = file->d_name;
			if (filename.find(extension, (filename.length() - extension.length())) != std::string::npos)
			{
				_filesArray[i] = new std::string(path + file->d_name);
				_filesNamesToIDs[prefix + file->d_name] = _filesArray[i];
				i++;
			}
		}
	}

	if (closedir(filesDir) == -1)
	{
		throw ManagerException(1004, "Error when closing directory\n\terrno: " + errno);
	}
}

FilesManager::~FilesManager()
{
	int size = _filesArray.size();
	for (int i = 0; i < size; i++)
	{
		delete _filesArray[i];
	}
	_filesArray.clear();
	_filesNamesToIDs.clear();
}

const std::string* FilesManager::getFile(int fileID) const
{
	if (_filesArray.find(fileID) != _filesArray.end())
	{
		return _filesArray.at(fileID);
	}
	throw ManagerException(1005, "Bad ID: " + fileID);
}

const std::string* FilesManager::getFile(std::string fileName) const
{
	if (_filesNamesToIDs.find(fileName) != _filesNamesToIDs.end())
	{
		return _filesNamesToIDs.at(fileName);
	}
	throw ManagerException(1006, "Bad filename: " + fileName);
}

FilesManager* FilesManager::getInstance()
{
	if (_singleton == NULL)
	{
		try
		{
			_singleton = new FilesManager;
		}
		catch(const std::exception &e)
		{
			sf::err() << e.what() << std::endl;
			exit(1007);
		}
	}
	return _singleton;
}

void FilesManager::kill()
{
		delete _singleton;
		_singleton = NULL;
}
