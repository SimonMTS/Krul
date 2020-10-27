#include "pch.h"
#include "AddNumbersFromStack.h"

int AddNumbersFromStack::Do(MemoryData& data, int i) {
	ExceptionHelper::StackContainsEnoughArguments(2, data, "AddNumbersFromStack", i + 1);

	int number1 = ExceptionHelper::SecureConvertToInt(data.stack.back(), "AddNumbersFromStack", i + 1);
	data.stack.pop_back();

	int number2 = ExceptionHelper::SecureConvertToInt(data.stack.back(), "AddNumbersFromStack", i + 1);
	data.stack.pop_back();

	int res = number1 + number2;

	data.stack.push_back(std::to_string(res));

	return i;
}

std::unique_ptr<Action> AddNumbersFromStack::Match(MemoryData & data, int i, std::string line) {
	std::regex e("^add$");

	if (std::regex_match(line, e)) {
		return std::unique_ptr<Action>(new AddNumbersFromStack());
	} else {
		return std::unique_ptr<Action>(nullptr);
	}
}
