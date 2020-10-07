#include "pch.h"
#include "NegateNumberFromStack.h"

int NegateNumberFromStack::Do(MemoryData& data, int i) {
	int number = std::stoi(data.stack.back());
	data.stack.pop_back();

	int res = -number;

	data.stack.push_back(std::to_string(res));

	return i;
}

std::unique_ptr<Action> NegateNumberFromStack::Match(MemoryData & data, int i, std::string line) {
	std::regex e("^neg$");

	if (std::regex_match(line, e)) {
		return std::unique_ptr<Action>(new NegateNumberFromStack());
	}
	else {
		return std::unique_ptr<Action>(nullptr);
	}
}
