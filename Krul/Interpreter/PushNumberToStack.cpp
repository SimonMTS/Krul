#include "pch.h"
#include "PushNumberToStack.h"

PushNumberToStack::PushNumberToStack(std::string n) {
	number = n;
}

void PushNumberToStack::Do(std::vector<std::string>& stack) {
	//std::cout << "PushNumberToStack\n";

	stack.push_back(number);
}

std::unique_ptr<Action> PushNumberToStack::Match(std::string line) {

	std::regex e("^\\d*$");

	if (std::regex_match(line, e)) {
		return std::unique_ptr<Action>( new PushNumberToStack(line) );
	} else {
		return std::unique_ptr<Action>(nullptr);
	}

}
