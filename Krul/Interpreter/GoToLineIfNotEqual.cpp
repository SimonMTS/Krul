#include "pch.h"
#include "GoToLineIfNotEqual.h"

int GoToLineIfNotEqual::Do(MemoryData& data, int i) {
	std::string label_value_str = data.stack.back();

	if (label_value_str.at(0) != '|') {
		std::string msg = "Runtime Error: GoToLineIfNotEqual called on a non linenumber value (doesn't start with a pipe). On line number " + std::to_string(i + 1) + ".";
		throw std::exception(msg.c_str());
	}

	data.stack.pop_back();

	int label_value;
	try {
		label_value_str.erase(0, 1);
		label_value = std::stoi(label_value_str);
	}
	catch (std::exception e) {
		std::string msg = "Runtime Error: GoToLineIfNotEqual called on a non linenumber value (value after pipe is not a number). On line number " + std::to_string(i + 1) + ".";
		throw std::exception(msg.c_str());
	}

	std::string value1 = data.stack.back();
	data.stack.pop_back();

	std::string value2 = data.stack.back();
	data.stack.pop_back();

	if (value1 == value2) {
		return i;
	} else {
		return label_value;
	}
}

std::unique_ptr<Action> GoToLineIfNotEqual::Match(MemoryData & data, int i, std::string line) {

	std::regex e("^gne$");

	if (std::regex_match(line, e)) {
		line.erase(0, 1);

		return std::unique_ptr<Action>(new GoToLineIfNotEqual());
	}
	else {
		return std::unique_ptr<Action>(nullptr);
	}

}