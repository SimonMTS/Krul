#include "pch.h"
#include "GetLengthOfStringFromStack.h"

int GetLengthOfStringFromStack::Do(MemoryData& data, int i) {
	ExceptionHelper::StackContainsEnoughArguments(1, data, "GetLengthOfStringFromStack", i + 1);

	std::string string = data.stack.back();
	data.stack.pop_back();

	std::string res = std::to_string(string.length());

	data.stack.push_back(res);

	return i;
}

std::unique_ptr<Action> GetLengthOfStringFromStack::Match(MemoryData & data, int i, std::string line) {
	std::regex e("^len$");

	if (std::regex_match(line, e)) {
		return std::unique_ptr<Action>(new GetLengthOfStringFromStack());
	} else {
		return std::unique_ptr<Action>(nullptr);
	}
}
