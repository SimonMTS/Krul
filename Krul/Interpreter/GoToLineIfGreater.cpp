#include "pch.h"
#include "GoToLineIfGreater.h"

int GoToLineIfGreater::Do(MemoryData& data, int i) {
	ExceptionHelper::StackContainsEnoughArguments(3, data, "GoToLineIfGreater", i + 1);

	std::string label_value_str = data.stack.back();
	ExceptionHelper::ValueIsLineNumberType(label_value_str, "GoToLineIfGreater", i + 1);
	data.stack.pop_back();

	label_value_str.erase(0, 1);
	int label_value = ExceptionHelper::SecureConvertToInt(label_value_str, "GoToLineIfGreater", i + 1);

	int value2 = ExceptionHelper::SecureConvertToInt(data.stack.back(), "GoToLineIfGreater", i + 1);
	data.stack.pop_back();

	int value1 = ExceptionHelper::SecureConvertToInt(data.stack.back(), "GoToLineIfGreater", i + 1);
	data.stack.pop_back();

	if (value1 > value2) {
		return label_value;
	} else {
		return i;
	}
}

std::unique_ptr<Action> GoToLineIfGreater::Match(MemoryData& data, int i, const std::string& line) {
	std::regex e("^ggt$");

	if (std::regex_match(line, e)) {
		return std::unique_ptr<Action>(new GoToLineIfGreater());
	} else {
		return std::unique_ptr<Action>(nullptr);
	}
}