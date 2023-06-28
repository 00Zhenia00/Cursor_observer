#include<fstream>
#include <iomanip>
#include <string>
#include <sstream>

#define _WIN32_WINNT 0x0A00
#include<windows.h>

#include "logger.h"


Logger::Logger(ISubject& subject) {

	subject.attach(this);

}

void Logger::update(const State& state) {

	std::ofstream out(".\\log.txt", std::ios::app);

	if (out) {

		if (state == State::in) {
			out << "Enter " << time_str();
		}
		else {
			out << "Leave " << time_str();
		}

	}
	else
		throw std::runtime_error("Not possible to open log file!");

}

std::string Logger::time_str() {
	SYSTEMTIME t;
	GetLocalTime(&t);

	std::stringstream s;

	s << std::setw(2) << std::setfill('0') << t.wHour << ":" <<
		std::setw(2) << std::setfill('0') << t.wMinute << ":" <<
		std::setw(2) << std::setfill('0') << t.wSecond << std::endl;

	return s.str();
}
