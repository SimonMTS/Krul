#include "pch.h"
#include "AddNumbersFromStack.h"

void AddNumbersFromStack::Do(std::vector<std::string>& stack) {
	int number1 = std::stoi( stack.back() );
	stack.pop_back();

	int number2 = std::stoi( stack.back() );
	stack.pop_back();

	int res = number1 + number2;

	stack.push_back(std::to_string(res));
}

std::unique_ptr<Action> AddNumbersFromStack::Match(std::string line) {
	std::regex e("^add$");

	if (std::regex_match(line, e)) {
		return std::unique_ptr<Action>(new AddNumbersFromStack());
	}
	else {
		return std::unique_ptr<Action>(nullptr);
	}
}