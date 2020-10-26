#include "pch.h"
#include "AddNewLineToStringFromStack.h"

int AddNewLineToStringFromStack::Do(MemoryData& data, int i) {
	if (data.stack.size() < 1) {
		std::string msg = "Runtime Error: AddNewLineToStringFromStack called on empty stack. On line number " + std::to_string(i + 1) + ".";
		throw std::exception(msg.c_str());
	}

	std::string string = data.stack.back();
	data.stack.pop_back();

	string += "\n";

	data.stack.push_back(string);

	return i;
}

std::unique_ptr<Action> AddNewLineToStringFromStack::Match(MemoryData & data, int i, std::string line) {
	std::regex e("^enl$");

	if (std::regex_match(line, e)) {
		return std::unique_ptr<Action>(new AddNewLineToStringFromStack());
	}
	else {
		return std::unique_ptr<Action>(nullptr);
	}
}
