#include "pch.h"
#include "ReverseStringFromStack.h"

int ReverseStringFromStack::Do(MemoryData& data, int i) {
	if (data.stack.size() < 1) {
		std::string msg = "Runtime Error: ReverseStringFromStack called on empty stack. On line number " + std::to_string(i + 1) + ".";
		throw std::exception(msg.c_str());
	}

	std::string string = data.stack.back();
	data.stack.pop_back();

	std::reverse(string.begin(), string.end());

	data.stack.push_back(string);

	return i;
}

std::unique_ptr<Action> ReverseStringFromStack::Match(MemoryData & data, int i, std::string line) {
	std::regex e("^rev$");

	if (std::regex_match(line, e)) {
		return std::unique_ptr<Action>(new ReverseStringFromStack());
	}
	else {
		return std::unique_ptr<Action>(nullptr);
	}
}

