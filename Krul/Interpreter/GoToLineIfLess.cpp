#include "pch.h"
#include "GoToLineIfLess.h"

int GoToLineIfLess::Do(MemoryData& data, int i) {
	std::string label_value_str = data.stack.back();
	data.stack.pop_back();
	label_value_str.erase(0, 1);
	int label_value = std::stoi(label_value_str);

	int value2 = std::stoi(data.stack.back());
	data.stack.pop_back();

	int value1 = std::stoi(data.stack.back());
	data.stack.pop_back();

	if (value1 < value2) {
		return label_value;
	}
	else {
		return i;
	}
}

std::unique_ptr<Action> GoToLineIfLess::Match(MemoryData& data, int i, std::string line) {

	std::regex e("^glt$");

	if (std::regex_match(line, e)) {
		line.erase(0, 1);

		return std::unique_ptr<Action>(new GoToLineIfLess());
	}
	else {
		return std::unique_ptr<Action>(nullptr);
	}

}
