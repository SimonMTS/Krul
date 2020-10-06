#include "pch.h"
#include "IndexStringFromStack.h"

void IndexStringFromStack::Do(std::vector<std::string>& stack) {
	int index = std::stoi(stack.back());
	stack.pop_back();

	std::string string = stack.back();
	stack.pop_back();

	std::string res{ string.at(index) };

	stack.push_back(res);
}

std::unique_ptr<Action> IndexStringFromStack::Match(std::string line) {
	std::regex e("^idx$");

	if (std::regex_match(line, e)) {
		return std::unique_ptr<Action>(new IndexStringFromStack());
	}
	else {
		return std::unique_ptr<Action>(nullptr);
	}
}
