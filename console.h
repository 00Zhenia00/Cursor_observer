#pragma once
#include "observer.h"
#include "subject.h"

class Console: public IObserver {

public:

	Console(ISubject& subject);

	void update(const State& state) override;

};
