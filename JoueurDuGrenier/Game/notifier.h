#ifndef INCLUDE_NOTIFIER
#define INCLUDE_NOTIFIER

//Error codes start by 8000

#include <vector>
#include "listener.h"


typedef Notifier;

class Notifier
{
public:
	virtual void RegisterListener(Listener *listener);
	virtual void UnregisterListener(Listener *listener);

protected:
	virtual void Notify() const;

private:
	std::vector<Listener*> _listeners;
};

#endif