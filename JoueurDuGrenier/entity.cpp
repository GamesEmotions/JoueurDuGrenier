#include "entity.h"

void Entity::setVelocity(sf::Vector2f velocity)
{
	_Velocity = velocity;
}

void Entity::setVelocity(float vx, float vy)
{
	_Velocity.x = vx;
	_Velocity.y = vy;
}

sf::Vector2f Entity::getVelocity() const
{
	return _Velocity;
}

template <typename T>
void Entity::setProperty(Property<T>& p, T value)
{
	p->value = value;
}

template <typename T>
void Entity::addProperty(Property<T>& p)
{
	_Properties.push_back(p);
}

BaseProperty* Entity::getProperty(Entities name)
{
	for (int i = _Properties.begin; i < _Properties.size; i++)
	{
		if (_Properties.at(i)->getID() == name)
		{
			return _Properties.at(i);
		}
	}
}