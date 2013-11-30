#ifndef INCLUDE_FILESMANAGER
#define INCLUDE_FILESMANAGER

//Error codes start by 1000

#include "dirent.h"
#include <stdio.h>
#include <stdlib.h>
#include <SFML/Audio.hpp>
#include <string.h>
#include <unordered_map>
#include "../JdgExceptions.h"


class FilesManager
{
	private:
		static FilesManager* _singleton;
		std::unordered_map<int, std::string*> _filesArray;
		std::unordered_map<std::string, std::string*> _filesNamesToIDs;
		
		FilesManager();
		~FilesManager();

	public:
		const std::string* getFile(int fileID) const;
		const std::string* getFile(std::string fileName) const;
		static FilesManager* getInstance();
		static void kill();
};

#endif