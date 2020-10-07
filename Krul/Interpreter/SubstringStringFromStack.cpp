#include "pch.h"
#include "SubstringStringFromStack.h"

int SubstringStringFromStack::Do(MemoryData& data, int i) {
	int to = std::stoi(data.stack.back());
	data.stack.pop_back();

	int from = std::stoi(data.stack.back());
	data.stack.pop_back();

	std::string value = data.stack.back();
	data.stack.pop_back();

	std::string res = value.substr(from, to-from); // todo, this might not be correct

	data.stack.push_back(res);

	return i;
}

std::unique_ptr<Action> SubstringStringFromStack::Match(MemoryData & data, int i, std::string line) {
	std::regex e("^slc$");

	if (std::regex_match(line, e)) {
		return std::unique_ptr<Action>(new SubstringStringFromStack());
	}
	else {
		return std::unique_ptr<Action>(nullptr);
	}
}
