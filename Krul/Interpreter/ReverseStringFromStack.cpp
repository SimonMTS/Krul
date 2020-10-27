#include "pch.h"
#include "ReverseStringFromStack.h"

int ReverseStringFromStack::Do(MemoryData& data, int i) {
	ExceptionHelper::StackContainsEnoughArguments(1, data, "ReverseStringFromStack", i + 1);

	std::string string = data.stack.back();
	data.stack.pop_back();

	std::reverse(string.begin(), string.end());

	data.stack.push_back(string);

	return i;
}

std::unique_ptr<Action> ReverseStringFromStack::Match(MemoryData& data, int i, const std::string& line) {
	std::regex e("^rev$");

	if (std::regex_match(line, e)) {
		return std::unique_ptr<Action>(new ReverseStringFromStack());
	} else {
		return std::unique_ptr<Action>(nullptr);
	}
}

