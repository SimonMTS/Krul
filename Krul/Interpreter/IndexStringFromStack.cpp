#include "pch.h"
#include "IndexStringFromStack.h"

int IndexStringFromStack::Do(MemoryData& data, int i) {
	int index = std::stoi(data.stack.back());
	data.stack.pop_back();

	std::string string = data.stack.back();
	data.stack.pop_back();

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
