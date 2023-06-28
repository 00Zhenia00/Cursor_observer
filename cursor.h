#pragma once
#include "subject.h"
#include<list>
#include<string>

#define _WIN32_WINNT 0x0A00
#include<windows.h>

class Cursor: public ISubject {

public:

	void attach(IObserver* observer) override;
	void detach(IObserver* observer) override;
	void notify() override;

	void track();

private:

	// ! Return if mouse cursor is in given rectangle
	bool cursor_in_rect(const POINT& p, const RECT& rct);

private:
	std::list<IObserver*> observers;
	State state{State::in};
};
