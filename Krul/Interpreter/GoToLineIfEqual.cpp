#include "pch.h"
#include "GoToLineIfEqual.h"

int GoToLineIfEqual::Do(MemoryData& data, int i) {
	std::string label_value_str = data.stack.back();
	data.stack.pop_back();
	label_value_str.erase(0, 1);
	int label_value = std::stoi(label_value_str);

	std::string value1 = data.stack.back();
	data.stack.pop_back();

	std::string value2 = data.stack.back();
	data.stack.pop_back();

	if (value1 == value2) {
		return label_value;
	}
	else {
		return i;
	}
}

std::unique_ptr<Action> GoToLineIfEqual::Match(MemoryData& data, int i, std::string line) {

	std::regex e("^geq$");

	if (std::regex_match(line, e)) {
		line.erase(0, 1);

		return std::unique_ptr<Action>(new GoToLineIfEqual());
	}
	else {
		return std::unique_ptr<Action>(nullptr);
	}

}
