#include "pch.h"
#include "NegateNumberFromStack.h"

void NegateNumberFromStack::Do(std::vector<std::string>& stack) {
	int number = std::stoi(stack.back());
	stack.pop_back();

	int res = -number;

	stack.push_back(std::to_string(res));
}

std::unique_ptr<Action> NegateNumberFromStack::Match(std::string line) {
	std::regex e("^neg$");

	if (std::regex_match(line, e)) {
		return std::unique_ptr<Action>(new NegateNumberFromStack());
	}
	else {
		return std::unique_ptr<Action>(nullptr);
	}
}
