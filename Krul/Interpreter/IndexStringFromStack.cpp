#include "pch.h"
#include "IndexStringFromStack.h"

int IndexStringFromStack::Do(MemoryData& data, int i) {
	if (data.stack.size() < 2) {
		std::string msg = "Runtime Error: IndexStringFromStack called on stack with only " + std::to_string(data.stack.size()) + " value. On line number " + std::to_string(i + 1) + ".";
		throw std::exception(msg.c_str());
	}
	
	int index;
	try {
		index = std::stoi(data.stack.back());
		data.stack.pop_back();
	} catch(std::exception e) {
		std::string msg = "Runtime Error: IndexStringFromStack called with non number index. On line number " + std::to_string(i + 1) + ".";
		throw std::exception(msg.c_str());
	}

	std::string string = data.stack.back();
	data.stack.pop_back();

	// todo maybe try catch this
	std::string res{ string.at(index) };

	data.stack.push_back(res);

	return i;
}

std::unique_ptr<Action> IndexStringFromStack::Match(MemoryData & data, int i, std::string line) {
	std::regex e("^idx$");

	if (std::regex_match(line, e)) {
		return std::unique_ptr<Action>(new IndexStringFromStack());
	}
	else {
		return std::unique_ptr<Action>(nullptr);
	}
}
