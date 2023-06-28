#pragma once
#include<string>
#include "state.h"

class IObserver {

public:

	virtual void update(const State& state) = 0;	// handle event
	virtual	~IObserver() {};

};