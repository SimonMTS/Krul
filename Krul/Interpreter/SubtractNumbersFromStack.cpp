#include "pch.h"
#include "SubtractNumbersFromStack.h"

int SubtractNumbersFromStack::Do(MemoryData& data, int i) {
	int number2 = std::stoi(data.stack.back());
	data.stack.pop_back();

	int number1 = std::stoi(data.stack.back());
	data.stack.pop_back();

	int res = number1 - number2;

	data.stack.push_back(std::to_string(res));

	return i;
}

std::unique_ptr<Action> SubtractNumbersFromStack::Match(MemoryData & data, int i, std::string line) {
	std::regex e("^sub");

	if (std::regex_match(line, e)) {
		return std::unique_ptr<Action>(new SubtractNumbersFromStack());
	}
	else {
		return std::unique_ptr<Action>(nullptr);
	}
}
