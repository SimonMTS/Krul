#include "pch.h"
#include "SubstringStringFromStack.h"

void SubstringStringFromStack::Do(std::vector<std::string>& stack) {
	int to = std::stoi(stack.back());
	stack.pop_back();

	int from = std::stoi(stack.back());
	stack.pop_back();

	std::string value = stack.back();
	stack.pop_back();

	std::string res = value.substr(from, to-2); // todo, this might not be correct

	stack.push_back(res);
}

std::unique_ptr<Action> SubstringStringFromStack::Match(std::string line) {
	std::regex e("^slc$");

	if (std::regex_match(line, e)) {
		return std::unique_ptr<Action>(new SubstringStringFromStack());
	}
	else {
		return std::unique_ptr<Action>(nullptr);
	}
}
