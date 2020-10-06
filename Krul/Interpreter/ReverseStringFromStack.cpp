#include "pch.h"
#include "ReverseStringFromStack.h"

void ReverseStringFromStack::Do(std::vector<std::string>& stack) {
	std::string string = stack.back();
	stack.pop_back();

	std::reverse(string.begin(), string.end());

	stack.push_back(string);
}

std::unique_ptr<Action> ReverseStringFromStack::Match(std::string line) {
	std::regex e("^rev$");

	if (std::regex_match(line, e)) {
		return std::unique_ptr<Action>(new ReverseStringFromStack());
	}
	else {
		return std::unique_ptr<Action>(nullptr);
	}
}

