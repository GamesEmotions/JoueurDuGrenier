#ifndef INCLUDE_ENTITY
#define INCLUDE_ENTITY

#include "SFML/System.hpp"
#include "property.h"
#include <vector>


class Entity
{
public:
	void setVelocity(sf::Vector2f velocity);
	void setVelocity(float vx, float vy);
	sf::Vector2f getVelocity() const;
	template <typename T>
	void setProperty(Property& p, value);
	template <typename T>
	void addProperty(Property& p);
	BaseProperty* getProperty(Entities name);

protected:
	Entities _ID;
	sf::Vector2f _Velocity;
	std::vector<BaseProperty*> _Properties;
};

#endif