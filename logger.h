#pragma once
#include "observer.h"
#include "subject.h"

class Logger : public IObserver {

public:

	Logger(ISubject& subject);

	void update(const State& state) override;

private:

	// ! Return string with current time
	std::string time_str();

};
