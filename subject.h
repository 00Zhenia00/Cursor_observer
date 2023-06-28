#pragma once
#include "observer.h"

class ISubject {

public:
	virtual void attach(IObserver* observer) = 0;
	virtual void detach(IObserver* observer) = 0;
	virtual void notify() = 0;

	virtual ~ISubject() {};

};