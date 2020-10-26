#include "pch.h"
#include "DecrementNumberFromStack.h"

int DecrementNumberFromStack::Do(MemoryData& data, int i) {
	int number;
	try {
		number = std::stoi(data.stack.back());
	} catch (std::exception e) {
		std::string msg = "Runtime Error: DecrementNumberFromStack called on a non number value. On line number " + std::to_string(i + 1) + ".";
		throw std::exception(msg.c_str());
	}

	data.stack.pop_back();

	int res = --number;

	data.stack.push_back(std::to_string(res));

	return i;
}

std::unique_ptr<Action> DecrementNumberFromStack::Match(MemoryData & data, int i, std::string line) {
	std::regex e("^dec$");

	if (std::regex_match(line, e)) {
		return std::unique_ptr<Action>(new DecrementNumberFromStack());
	}
	else {
		return std::unique_ptr<Action>(nullptr);
	}
}
