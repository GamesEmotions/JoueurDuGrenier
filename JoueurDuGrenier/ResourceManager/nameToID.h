#ifndef INCLUDE_NAMETOID
#define INCLUDE_NAMETOID

#include <string>

class NameToID
{
	public:
		NameToID(int id, std::string name);
		~NameToID();
	
		int _id;
		std::string _name;
};

#endif