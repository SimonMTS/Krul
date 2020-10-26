#include "pch.h"
#include "AssignVariableFromStack.h"

AssignVariableFromStack::AssignVariableFromStack(std::string n) {
	name = n;
}

int AssignVariableFromStack::Do(MemoryData& data, int i) {
	if (data.stack.size() < 1) {
		std::string msg = "Runtime Error: AssignVariableFromStack called on empty stack. On line number " + std::to_string(i + 1) + ".";
		throw std::exception(msg.c_str());
	}

	std::string string = data.stack.back();
	data.stack.pop_back();

	data.variables[name] = string;

	return i;
}

std::unique_ptr<Action> AssignVariableFromStack::Match(MemoryData & data, int i, std::string line) {

	std::regex e("^=.*$");

	if (std::regex_match(line, e)) {
		line.erase(0, 1);

		return std::unique_ptr<Action>(new AssignVariableFromStack(line));
	}
	else {
		return std::unique_ptr<Action>(nullptr);
	}

}