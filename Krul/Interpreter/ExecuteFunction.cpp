#include "pch.h"
#include "ExecuteFunction.h"
#include "GoToLine.h"

int ExecuteFunction::Do(MemoryData& data, int i) {
	ExceptionHelper::StackContainsEnoughArguments(1, data, "ExecuteFunction", i + 1);

	data.callStack.push_back("|" + std::to_string(i));

	std::string label_value_str = data.stack.back();
	data.stack.pop_back();

	ExceptionHelper::ValueIsLineNumberType(label_value_str, "ExecuteFunction", i + 1);

	label_value_str.erase(0, 1);
	int label_value = ExceptionHelper::SecureConvertToInt(label_value_str, "ExecuteFunction", i + 1);

	return label_value;
}

std::unique_ptr<Action> ExecuteFunction::Match(MemoryData& data, int i, std::string line) {
	std::regex e("^fun$");

	if (std::regex_match(line, e)) {
		line.erase(0, 1);

		return std::unique_ptr<Action>(new ExecuteFunction());
	} else {
		return std::unique_ptr<Action>(nullptr);
	}
}
