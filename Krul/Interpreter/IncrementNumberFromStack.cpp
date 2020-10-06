#include "pch.h"
#include "IncrementNumberFromStack.h"

void IncrementNumberFromStack::Do(std::vector<std::string>& stack) {
	int number = std::stoi(stack.back());
	stack.pop_back();

	int res = ++number;

	stack.push_back(std::to_string(res));
}

std::unique_ptr<Action> IncrementNumberFromStack::Match(std::string line) {
	std::regex e("^inc$");

	if (std::regex_match(line, e)) {
		return std::unique_ptr<Action>(new IncrementNumberFromStack());
	}
	else {
		return std::unique_ptr<Action>(nullptr);
	}
}
