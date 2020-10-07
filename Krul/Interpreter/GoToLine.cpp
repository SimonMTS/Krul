#include "pch.h"
#include "GoToLine.h"

int GoToLine::Do(MemoryData& data, int i) {
	std::string label_value_str = data.stack.back();
	data.stack.pop_back();
	label_value_str.erase(0, 1);
	int label_value = std::stoi(label_value_str);

	return label_value;
}

std::unique_ptr<Action> GoToLine::Match(MemoryData& data, int i, std::string line) {

	std::regex e("^gto$");

	if (std::regex_match(line, e)) {
		line.erase(0, 1);

		return std::unique_ptr<Action>(new GoToLine());
	}
	else {
		return std::unique_ptr<Action>(nullptr);
	}

}