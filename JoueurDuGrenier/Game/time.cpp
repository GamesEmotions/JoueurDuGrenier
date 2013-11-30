#include "time.h"


GameTicker::GameTicker(sf::Time interval) : _interval(interval)
{
	_clock = new sf::Clock();
	_listeners = std::unordered_set<Listener*>();
}

GameTicker::~GameTicker()
{
	delete _clock;
}

void GameTicker::tick()
{
	if (_clock->getElapsedTime() >= _interval)
	{
		Notify();
	}
}

const sf::Time GameTicker::getInterval() const
{
	return sf::Time(_interval);
}

void GameTicker::setInterval(sf::Time newInterval)
{
	_interval = newInterval;
}

void GameTicker::RegisterListener(Listener* listener)
{
	_listeners.insert(listener);
}

void GameTicker::UnregisterListener(Listener* listener)
{
	_listeners.erase(listener);
}

void GameTicker::Notify() const
{
	for (Listener* l: _listeners)
	{
		l->getNotification(this);
	}
}