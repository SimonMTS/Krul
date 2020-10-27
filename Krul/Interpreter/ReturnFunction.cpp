#include "pch.h"
#include "ReturnFunction.h"
#include "GoToLine.h"

int ReturnFunction::Do(MemoryData& data, int i) {
	ExceptionHelper::StackContainsEnoughArguments(1, data, "ReturnFunction", i + 1);

	std::string callStack_value_str = data.callStack.back();
	data.callStack.pop_back();

	callStack_value_str.erase(0, 1);
	int callStack_value = ExceptionHelper::SecureConvertToInt(callStack_value_str, "ReturnFunction", i + 1);

	return callStack_value;
}

std::unique_ptr<Action> ReturnFunction::Match(MemoryData& data, int i, const std::string& line) {
	std::regex e("^ret$");

	if (std::regex_match(line, e)) {
		return std::unique_ptr<Action>(new ReturnFunction());
	} else {
		return std::unique_ptr<Action>(nullptr);
	}
}
