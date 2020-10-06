#include "pch.h"
#include "DecrementNumberFromStack.h"

void DecrementNumberFromStack::Do(std::vector<std::string>& stack) {
	int number = std::stoi(stack.back());
	stack.pop_back();

	int res = --number;

	stack.push_back(std::to_string(res));
}

std::unique_ptr<Action> DecrementNumberFromStack::Match(std::string line) {
	std::regex e("^dec$");

	if (std::regex_match(line, e)) {
		return std::unique_ptr<Action>(new DecrementNumberFromStack());
	}
	else {
		return std::unique_ptr<Action>(nullptr);
	}
}
