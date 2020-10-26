#include "pch.h"
#include "ConcatenateStringFromStack.h"

int ConcatenateStringFromStack::Do(MemoryData& data, int i) {
	if (data.stack.size() < 2) {
		std::string msg = "Runtime Error: ConcatenateStringFromStack called on stack with only " + std::to_string(data.stack.size()) + " value. On line number " + std::to_string(i + 1) + ".";
		throw std::exception(msg.c_str());
	}

	std::string string1 = data.stack.back();
	data.stack.pop_back();

	std::string string2 = data.stack.back();
	data.stack.pop_back();

	std::string res = string2 + string1;

	data.stack.push_back(res);

	return i;
}

std::unique_ptr<Action> ConcatenateStringFromStack::Match(MemoryData & data, int i, std::string line) {
	std::regex e("^cat$");

	if (std::regex_match(line, e)) {
		return std::unique_ptr<Action>(new ConcatenateStringFromStack());
	}
	else {
		return std::unique_ptr<Action>(nullptr);
	}
}
