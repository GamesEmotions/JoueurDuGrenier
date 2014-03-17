#ifndef INCLUDE_PLAYER
#define INCLUDE_PLAYER

#include "SFML/Graphics.hpp"
#include "entity.h"


class Player : public Entity
{
public:
	enum Type {Fred,Seb};

	explicit Player(Type type);

private:
	Type _Type;
};

#endif