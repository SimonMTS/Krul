#include "pch.h"
#include "MakeAbsoluteNumberFromStack.h"

void MakeAbsoluteNumberFromStack::Do(std::vector<std::string>& stack) {
	int number = std::stoi(stack.back());
	stack.pop_back();

	int res = std::abs(number);

	stack.push_back(std::to_string(res));
}

std::unique_ptr<Action> MakeAbsoluteNumberFromStack::Match(std::string line) {
	std::regex e("^abs$");

	if (std::regex_match(line, e)) {
		return std::unique_ptr<Action>(new MakeAbsoluteNumberFromStack());
	}
	else {
		return std::unique_ptr<Action>(nullptr);
	}
}
