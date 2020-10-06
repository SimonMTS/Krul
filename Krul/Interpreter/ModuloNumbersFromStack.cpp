#include "pch.h"
#include "ModuloNumbersFromStack.h"

void ModuloNumbersFromStack::Do(std::vector<std::string>& stack) {
	int number1 = std::stoi(stack.back());
	stack.pop_back();

	int number2 = std::stoi(stack.back());
	stack.pop_back();

	int res = number2 % number1;

	stack.push_back(std::to_string(res));
}

std::unique_ptr<Action> ModuloNumbersFromStack::Match(std::string line) {
	std::regex e("^mod$");

	if (std::regex_match(line, e)) {
		return std::unique_ptr<Action>(new ModuloNumbersFromStack());
	}
	else {
		return std::unique_ptr<Action>(nullptr);
	}
}
