#ifndef INCLUDE_BASEPROPERTY
#define INCLUDE_BASEPROPERTY


enum class Entities {Alf_Bat,Alf_Spy,Player,Player_Ball};

class BaseProperty
{
public:
	BaseProperty();
	~BaseProperty();
	Entities getID();

protected:
	Entities _ID;
};

Entities BaseProperty::getID()
{
	return _ID;
}

#endif