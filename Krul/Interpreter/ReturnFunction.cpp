#include "pch.h"
#include "ReturnFunction.h"
#include "GoToLine.h"

int ReturnFunction::Do(MemoryData& data, int i) {
	std::string callStack_value_str = data.callStack.back();
	data.callStack.pop_back();
	callStack_value_str.erase(0, 1);
	int callStack_value = std::stoi(callStack_value_str);

	//auto gto = GoToLine();
	//return gto.Do(data, callStack_value);
	return callStack_value;
}

std::unique_ptr<Action> ReturnFunction::Match(MemoryData& data, int i, std::string line) {

	std::regex e("^ret$");

	if (std::regex_match(line, e)) {
		line.erase(0, 1);

		return std::unique_ptr<Action>(new ReturnFunction());
	}
	else {
		return std::unique_ptr<Action>(nullptr);
	}

}