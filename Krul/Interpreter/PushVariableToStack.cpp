#include "pch.h"
#include "PushVariableToStack.h"

PushVariableToStack::PushVariableToStack(std::string n) {
	name = n;
}

int PushVariableToStack::Do(MemoryData& data, int i) {
	std::string string = data.variables[name];

	data.stack.push_back(string);

	return i;
}

std::unique_ptr<Action> PushVariableToStack::Match(MemoryData & data, int i, std::string line) {

	std::regex e("^\\$.*$");

	if (std::regex_match(line, e)) {
		line.erase(0, 1);

		return std::unique_ptr<Action>(new PushVariableToStack(line));
	}
	else {
		return std::unique_ptr<Action>(nullptr);
	}

}