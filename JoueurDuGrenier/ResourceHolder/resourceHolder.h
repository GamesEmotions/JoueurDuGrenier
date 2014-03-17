#ifndef INCLUDE_RESOURCEHOLDER
#define INCLUDE_RESOURCEHOLDER

#include <map>
#include <memory>
#include <assert.h>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"


enum class Tiles {Grass1,Grass2,Grass3,Building1,Building2,Tree1,Size};
enum class Entities {Player,AlfBat,AlfSpy,Size};
enum class Backgrounds {Day,Night,Manufacture,Size};
enum class Sounds {PlayerHit,PlayerSalami,PlayerGamepad,PlayerBall,PlayerDamage,PlayerDied,AlfBat,AlfBatDied,AlfSpyDied,Size};
enum class Musics {City1,City2,Forest1,Manufacture1,Sewers1,Size};


template <typename Resource, typename Identifier>
class ResourceHolder
{
private:
	ResourceHolder();
	~ResourceHolder();

	static ResourceHolder* _singleton;

	std::map<Identifier,std::unique_ptr<Resource>> _ResourcesHolder;

public:
	static ResourceHolder* getInstance();
	void load(Identifier id, const std::string& filename);
	template <typename Parameter>
	void load(Identifier id, const std::string& filename, const Parameter& secondParameter);
	Resource& get(Identifier id);
	const Resource& get(Identifier id) const;
};

#include "resourceHolder.inl"

#endif