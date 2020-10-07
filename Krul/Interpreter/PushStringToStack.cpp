#include "pch.h"
#include "PushStringToStack.h"

PushStringToStack::PushStringToStack(std::string s) {
	string = s;
}

int PushStringToStack::Do(MemoryData& data, int i) {
	data.stack.push_back(string);

	return i;
}

std::unique_ptr<Action> PushStringToStack::Match(MemoryData & data, int i, std::string line) {

	std::regex e("^\\\\.*$");

	if (std::regex_match(line, e)) {
		line.erase(0, 1);

		return std::unique_ptr<Action>(new PushStringToStack(line));
	} else {
		return std::unique_ptr<Action>(nullptr);
	}

}

