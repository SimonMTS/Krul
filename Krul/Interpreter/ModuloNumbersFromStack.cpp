#include "pch.h"
#include "ModuloNumbersFromStack.h"

int ModuloNumbersFromStack::Do(MemoryData& data, int i) {
	ExceptionHelper::StackContainsEnoughArguments(2, data, "ModuloNumbersFromStack", i + 1);

	int number1 = ExceptionHelper::SecureConvertToInt(data.stack.back(), "ModuloNumbersFromStack", i + 1);
	data.stack.pop_back();

	int number2 = ExceptionHelper::SecureConvertToInt(data.stack.back(), "ModuloNumbersFromStack", i + 1);
	data.stack.pop_back();

	int res = number2 % number1;

	data.stack.push_back(std::to_string(res));

	return i;
}

std::unique_ptr<Action> ModuloNumbersFromStack::Match(MemoryData & data, int i, std::string line) {
	std::regex e("^mod$");

	if (std::regex_match(line, e)) {
		return std::unique_ptr<Action>(new ModuloNumbersFromStack());
	} else {
		return std::unique_ptr<Action>(nullptr);
	}
}
