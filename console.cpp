#include<iostream>
#include "console.h"

Console::Console(ISubject& subject) {

	subject.attach(this);

}

void Console::update(const State& state) {

	if (state == State::in) {
		system("color 02");
	}
	else {
		system("color 07");
	}

}