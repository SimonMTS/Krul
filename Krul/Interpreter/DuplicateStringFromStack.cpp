#include "pch.h"
#include "DuplicateStringFromStack.h"

void DuplicateStringFromStack::Do(std::vector<std::string>& stack) {
	stack.push_back(stack.back());
}

std::unique_ptr<Action> DuplicateStringFromStack::Match(std::string line) {
	std::regex e("^dup$");

	if (std::regex_match(line, e)) {
		return std::unique_ptr<Action>(new DuplicateStringFromStack());
	}
	else {
		return std::unique_ptr<Action>(nullptr);
	}
}
