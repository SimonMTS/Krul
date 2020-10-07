#include "pch.h"
#include "ModuloNumbersFromStack.h"

int ModuloNumbersFromStack::Do(MemoryData& data, int i) {
	int number1 = std::stoi(data.stack.back());
	data.stack.pop_back();

	int number2 = std::stoi(data.stack.back());
	data.stack.pop_back();

	int res = number2 % number1;

	data.stack.push_back(std::to_string(res));

	return i;
}

std::unique_ptr<Action> ModuloNumbersFromStack::Match(MemoryData & data, int i, std::string line) {
	std::regex e("^mod$");

	if (std::regex_match(line, e)) {
		return std::unique_ptr<Action>(new ModuloNumbersFromStack());
	}
	else {
		return std::unique_ptr<Action>(nullptr);
	}
}
