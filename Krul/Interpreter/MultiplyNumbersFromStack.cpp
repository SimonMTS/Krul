#include "pch.h"
#include "MultiplyNumbersFromStack.h"

int MultiplyNumbersFromStack::Do(MemoryData& data, int i) {
	ExceptionHelper::StackContainsEnoughArguments(2, data, "MultiplyNumbersFromStack", i + 1);

	int number1 = ExceptionHelper::SecureConvertToInt(data.stack.back(), "MultiplyNumbersFromStack", i + 1);
	data.stack.pop_back();

	int number2 = ExceptionHelper::SecureConvertToInt(data.stack.back(), "MultiplyNumbersFromStack", i + 1);
	data.stack.pop_back();

	int res = number1 * number2;

	data.stack.push_back(std::to_string(res));

	return i;
}

std::unique_ptr<Action> MultiplyNumbersFromStack::Match(MemoryData & data, int i, std::string line) {
	std::regex e("^mul$");

	if (std::regex_match(line, e)) {
		return std::unique_ptr<Action>(new MultiplyNumbersFromStack());
	} else {
		return std::unique_ptr<Action>(nullptr);
	}
}
