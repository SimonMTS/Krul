#include "pch.h"
#include "GetLengthOfStringFromStack.h"

void GetLengthOfStringFromStack::Do(std::vector<std::string>& stack) {
	std::string string = stack.back();
	stack.pop_back();

	std::string res = std::to_string(string.length());

	stack.push_back(res);
}

std::unique_ptr<Action> GetLengthOfStringFromStack::Match(std::string line) {
	std::regex e("^len$");

	if (std::regex_match(line, e)) {
		return std::unique_ptr<Action>(new GetLengthOfStringFromStack());
	}
	else {
		return std::unique_ptr<Action>(nullptr);
	}
}
