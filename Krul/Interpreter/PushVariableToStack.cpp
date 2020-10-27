#include "pch.h"
#include "PushVariableToStack.h"

PushVariableToStack::PushVariableToStack(std::string n) {
	name = n;
}

int PushVariableToStack::Do(MemoryData& data, int i) {
	ExceptionHelper::VariableIsDeclared(name, data, "PushVariableToStack", i + 1);

	std::string string = data.variables[name];

	data.stack.push_back(string);

	return i;
}

std::unique_ptr<Action> PushVariableToStack::Match(MemoryData& data, int i, const std::string& line) {
	std::regex e("^\\$.*$");

	if (std::regex_match(line, e)) {
		std::string string = line;
		string.erase(0, 1);

		return std::unique_ptr<Action>(new PushVariableToStack(string));
	} else {
		return std::unique_ptr<Action>(nullptr);
	}
}