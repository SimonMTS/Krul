#include "pch.h"
#include "NegateNumberFromStack.h"

int NegateNumberFromStack::Do(MemoryData& data, int i) {
	ExceptionHelper::StackContainsEnoughArguments(1, data, "NegateNumberFromStack", i + 1);

	int number = ExceptionHelper::SecureConvertToInt(data.stack.back(), "NegateNumberFromStack", i + 1);
	data.stack.pop_back();

	int res = -number;

	data.stack.push_back(std::to_string(res));

	return i;
}

std::unique_ptr<Action> NegateNumberFromStack::Match(MemoryData & data, int i, std::string line) {
	std::regex e("^neg$");

	if (std::regex_match(line, e)) {
		return std::unique_ptr<Action>(new NegateNumberFromStack());
	} else {
		return std::unique_ptr<Action>(nullptr);
	}
}
