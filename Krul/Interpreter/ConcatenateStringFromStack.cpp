#include "pch.h"
#include "ConcatenateStringFromStack.h"

int ConcatenateStringFromStack::Do(MemoryData& data, int i) {
	ExceptionHelper::StackContainsEnoughArguments(2, data, "ConcatenateStringFromStack", i + 1);

	std::string string1 = data.stack.back();
	data.stack.pop_back();

	std::string string2 = data.stack.back();
	data.stack.pop_back();

	std::string res = string2 + string1;

	data.stack.push_back(res);

	return i;
}

std::unique_ptr<Action> ConcatenateStringFromStack::Match(MemoryData& data, int i, const std::string& line) {
	std::regex e("^cat$");

	if (std::regex_match(line, e)) {
		return std::unique_ptr<Action>(new ConcatenateStringFromStack());
	} else {
		return std::unique_ptr<Action>(nullptr);
	}
}
