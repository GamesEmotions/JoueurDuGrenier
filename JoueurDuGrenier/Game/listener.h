#ifndef INCLUDE_LISTENER
#define INCLUDE_LISTENER


#include "notifier.h"


class Listener
{
public:
	virtual ~Listener();
	virtual void getNotification(const Notifier* notifier) = 0;

protected:
	Listener();

private:
	Listener(const Listener& yRef);
	Listener& operator=(const Listener& yRef);
};

#endif