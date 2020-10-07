#include "pch.h"
#include "ExecuteFunction.h"
#include "GoToLine.h"

int ExecuteFunction::Do(MemoryData& data, int i) {
	data.callStack.push_back("|" + std::to_string(i));

	//auto gto = GoToLine();
	//return gto.Do(data, i);

	std::string label_value_str = data.stack.back();
	data.stack.pop_back();
	label_value_str.erase(0, 1);
	int label_value = std::stoi(label_value_str);

	return label_value;
}

std::unique_ptr<Action> ExecuteFunction::Match(MemoryData& data, int i, std::string line) {

	std::regex e("^fun$");

	if (std::regex_match(line, e)) {
		line.erase(0, 1);

		return std::unique_ptr<Action>(new ExecuteFunction());
	}
	else {
		return std::unique_ptr<Action>(nullptr);
	}

}
