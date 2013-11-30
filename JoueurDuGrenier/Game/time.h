#ifndef INCLUDE_TIME
#define INCLUDE_TIME

//Error code start by 4000

#include <SFML/System/Clock.hpp>
#include "../JdgExceptions.h"
#include "notifier.h"
#include <unordered_set>

class GameTicker : Notifier
{
	public:
		GameTicker(sf::Time interval);
		~GameTicker();
		void tick();
		const sf::Time getInterval() const;
		void setInterval(sf::Time newInterval);
		virtual void RegisterListener(Listener* listener);
		virtual void UnregisterListener(Listener* listener);
		virtual void Notify() const;

	private:
		std::unordered_set<Listener*> _listeners;
		sf::Clock* _clock;
		sf::Time _interval;	//intervalle en milliseconde
};

#endif