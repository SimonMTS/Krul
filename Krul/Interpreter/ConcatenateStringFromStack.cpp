#include "pch.h"
#include "ConcatenateStringFromStack.h"

void ConcatenateStringFromStack::Do(std::vector<std::string>& stack) {
	std::string string1 = stack.back();
	stack.pop_back();

	std::string string2 = stack.back();
	stack.pop_back();

	std::string res = string1 + string2;

	stack.push_back(res);
}

std::unique_ptr<Action> ConcatenateStringFromStack::Match(std::string line) {
	std::regex e("^cat$");

	if (std::regex_match(line, e)) {
		return std::unique_ptr<Action>(new ConcatenateStringFromStack());
	}
	else {
		return std::unique_ptr<Action>(nullptr);
	}
}
