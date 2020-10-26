#include "pch.h"
#include "SubstringStringFromStack.h"

int SubstringStringFromStack::Do(MemoryData& data, int i) {
	if (data.stack.size() < 3) {
		std::string msg = "Runtime Error: SubstringStringFromStack called on stack with only " + std::to_string(data.stack.size()) + " value. On line number " + std::to_string(i + 1) + ".";
		throw std::exception(msg.c_str());
	}

	size_t to;
	size_t from;
	try {
		to = std::stoi(data.stack.back());
		data.stack.pop_back();

		from = std::stoi(data.stack.back());
		data.stack.pop_back();
	} catch(std::exception e) {
		std::string msg = "Runtime Error: SubstringStringFromStack called with a non number To or From value. On line number " + std::to_string(i + 1) + ".";
		throw std::exception(msg.c_str());
	}

	std::string value = data.stack.back();
	data.stack.pop_back();

	std::string res = value.substr(from, to - from);

	data.stack.push_back(res);

	return i;
}

std::unique_ptr<Action> SubstringStringFromStack::Match(MemoryData& data, int i, std::string line) {
	std::regex e("^slc$");

	if (std::regex_match(line, e)) {
		return std::unique_ptr<Action>(new SubstringStringFromStack());
	} else {
		return std::unique_ptr<Action>(nullptr);
	}
}
