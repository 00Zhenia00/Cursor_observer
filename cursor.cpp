#include <iostream>
#include<algorithm>
#include<memory>

#include "cursor.h"

void Cursor::attach(IObserver* observer) {

	observers.push_back(observer);
	
}

void Cursor::detach(IObserver* observer) {

	observers.remove(observer);

}

void Cursor::notify() {

	for (IObserver* observer : observers) {
		observer->update(state);
	}

}

void Cursor::track() {

	HWND hwnd = GetConsoleWindow();
	if (!hwnd)
		throw std::runtime_error("There is no process associated console!");

	RECT rect;
	GetClientRect(hwnd, &rect);

	POINT p;

	do {
		
		if (!GetCursorPos(&p))
			throw std::runtime_error("Not possible to get cursor position!");

		ScreenToClient(hwnd, &p);

		State cur_state;

		if (cursor_in_rect(p, rect))
			cur_state = State::in;
		else
			cur_state = State::out;


		if (cur_state != state) {
			state = cur_state;
			notify();
		}

	} while (GetKeyState(VK_ESCAPE) >= 0);

}

bool Cursor::cursor_in_rect(const POINT& p, const RECT& rct) {
	return (p.x > 0 && p.x < rct.right&& p.y > 0 && p.y < rct.bottom);
}