#include "pch.h"
#include "GoToLineIfLessOrEqual.h"

int GoToLineIfLessOrEqual::Do(MemoryData& data, int i) {
	ExceptionHelper::StackContainsEnoughArguments(3, data, "GoToLineIfLessOrEqual", i + 1);

	std::string label_value_str = data.stack.back();
	ExceptionHelper::ValueIsLineNumberType(label_value_str, "GoToLineIfLessOrEqual", i + 1);
	data.stack.pop_back();

	label_value_str.erase(0, 1);
	int label_value = ExceptionHelper::SecureConvertToInt(label_value_str, "GoToLineIfLessOrEqual", i + 1);

	int value2 = ExceptionHelper::SecureConvertToInt(data.stack.back(), "GoToLineIfLessOrEqual", i + 1);
	data.stack.pop_back();

	int value1 = ExceptionHelper::SecureConvertToInt(data.stack.back(), "GoToLineIfLessOrEqual", i + 1);
	data.stack.pop_back();

	if (value1 <= value2) {
		return label_value;
	} else {
		return i;
	}
}

std::unique_ptr<Action> GoToLineIfLessOrEqual::Match(MemoryData& data, int i, const std::string& line) {
	std::regex e("^gle$");

	if (std::regex_match(line, e)) {
		return std::unique_ptr<Action>(new GoToLineIfLessOrEqual());
	} else {
		return std::unique_ptr<Action>(nullptr);
	}
}


