#include "notifier.h"

void Notifier::Notify() const
{
	for (unsigned int i = 0; i < _listeners.size(); i++)
	{
		_listeners[i]->getNotification(this);
	}
}

void Notifier::RegisterListener(Listener *listener)
{
	_listeners.push_back(listener);
}

void Notifier::UnregisterListener(Listener *listener)
{
	int size = _listeners.size();
	for (int i = 0; i < size; i++)
	{
		if (_listeners.at(i) == listener)
		{
			_listeners.at(i) = nullptr;
			break;
		}
	}
	throw new std::exception("Can't unregister, listener not found", 8001);
}