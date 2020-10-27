#include "pch.h"
#include "GoToLineIfNotEqual.h"

int GoToLineIfNotEqual::Do(MemoryData& data, int i) {
	ExceptionHelper::StackContainsEnoughArguments(3, data, "GoToLineIfNotEqual", i + 1);

	std::string label_value_str = data.stack.back();
	ExceptionHelper::ValueIsLineNumberType(label_value_str, "GoToLineIfNotEqual", i + 1);
	data.stack.pop_back();

	label_value_str.erase(0, 1);
	int label_value = ExceptionHelper::SecureConvertToInt(label_value_str, "GoToLineIfNotEqual", i + 1);

	std::string value1 = data.stack.back();
	data.stack.pop_back();

	std::string value2 = data.stack.back();
	data.stack.pop_back();

	if (value1 == value2) {
		return i;
	} else {
		return label_value;
	}
}

std::unique_ptr<Action> GoToLineIfNotEqual::Match(MemoryData& data, int i, const std::string& line) {
	std::regex e("^gne$");

	if (std::regex_match(line, e)) {
		return std::unique_ptr<Action>(new GoToLineIfNotEqual());
	} else {
		return std::unique_ptr<Action>(nullptr);
	}
}