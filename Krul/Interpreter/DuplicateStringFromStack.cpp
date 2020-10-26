#include "pch.h"
#include "DuplicateStringFromStack.h"

int DuplicateStringFromStack::Do(MemoryData& data, int i) {
	if (data.stack.size() < 1) {
		std::string msg = "Runtime Error: DuplicateStringFromStack called on empty stack. On line number " + std::to_string(i + 1) + ".";
		throw std::exception(msg.c_str());
	}

	data.stack.push_back(data.stack.back());

	return i;
}

std::unique_ptr<Action> DuplicateStringFromStack::Match(MemoryData & data, int i, std::string line) {
	std::regex e("^dup$");

	if (std::regex_match(line, e)) {
		return std::unique_ptr<Action>(new DuplicateStringFromStack());
	}
	else {
		return std::unique_ptr<Action>(nullptr);
	}
}
