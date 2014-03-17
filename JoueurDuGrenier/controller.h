#ifndef INCLUDE_CONTROLLER
#define INCLUDE_CONTROLLER

#include "entity.h"
#include "property.h"
#include <vector>


class Controller
{
public:
	void run();

private:
	Entity* _Entity;
	std::vector<BaseProperty*> _PropertiesCache;
};

#endif