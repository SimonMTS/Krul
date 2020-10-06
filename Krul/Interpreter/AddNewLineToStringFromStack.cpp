#include "pch.h"
#include "AddNewLineToStringFromStack.h"

void AddNewLineToStringFromStack::Do(std::vector<std::string>& stack) {
	std::string string = stack.back();
	stack.pop_back();

	string += "\n";

	stack.push_back(string);
}

std::unique_ptr<Action> AddNewLineToStringFromStack::Match(std::string line) {
	std::regex e("^enl$");

	if (std::regex_match(line, e)) {
		return std::unique_ptr<Action>(new AddNewLineToStringFromStack());
	}
	else {
		return std::unique_ptr<Action>(nullptr);
	}
}
