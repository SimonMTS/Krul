#include "pch.h"
#include "PushStringToStack.h"

PushStringToStack::PushStringToStack(std::string s) {
	string = s;
}

void PushStringToStack::Do(std::vector<std::string>& stack) {
	stack.push_back(string);
}

std::unique_ptr<Action> PushStringToStack::Match(std::string line) {

	std::regex e("^\\\\\\w*$");

	if (std::regex_match(line, e)) {
		return std::unique_ptr<Action>(new PushStringToStack(line));
	}
	else {
		return std::unique_ptr<Action>(nullptr);
	}

}

