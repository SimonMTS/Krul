#include "pch.h"
#include "DuplicateStringFromStack.h"

int DuplicateStringFromStack::Do(MemoryData& data, int i) {
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
