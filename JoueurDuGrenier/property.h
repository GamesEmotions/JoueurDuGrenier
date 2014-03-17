#ifndef INCLUDE_PROPERTY
#define INCLUDE_PROPERTY

#include "baseProperty.h"


template <typename T>
class Property<T> : baseProperty
{
public:
	Property<T>();
	~Property<T>();

protected:
	T value;
};

#endif