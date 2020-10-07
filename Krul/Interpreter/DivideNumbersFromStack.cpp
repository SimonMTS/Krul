#include "pch.h"
#include "DivideNumbersFromStack.h"

int DivideNumbersFromStack::Do(MemoryData& data, int i) {
	int number2 = std::stoi(data.stack.back());
	data.stack.pop_back();

	int number1 = std::stoi(data.stack.back());
	data.stack.pop_back();

	int res = number1 / number2;

	data.stack.push_back(std::to_string(res));

	return i;
}

std::unique_ptr<Action> DivideNumbersFromStack::Match(MemoryData & data, int i, std::string line) {
	std::regex e("^div$");

	if (std::regex_match(line, e)) {
		return std::unique_ptr<Action>(new DivideNumbersFromStack());
	}
	else {
		return std::unique_ptr<Action>(nullptr);
	}
}
