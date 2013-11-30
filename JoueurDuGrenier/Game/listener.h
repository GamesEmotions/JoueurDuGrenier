#ifndef INCLUDE_LISTENER
#define INCLUDE_LISTENER


#include "notifier.h"

class Listener
{
public:
	virtual void getNotification(const Notifier* notifier) = 0;
};

#endif