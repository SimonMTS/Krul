#include "pch.h"
#include "PushLabelToStack.h"

PushLabelToStack::PushLabelToStack(std::string n) {
	name = n;
}

int PushLabelToStack::Do(MemoryData& data, int i) {
	if (data.labels.find(name) == data.labels.end()) {
		std::string msg = "Runtime Error: PushLabelToStack called with undeclared label name. On line number " + std::to_string(i + 1) + ".";
		throw std::exception(msg.c_str());
	}

	data.stack.push_back("|" + std::to_string(data.labels[name]));

	return i;
}

std::unique_ptr<Action> PushLabelToStack::Match(MemoryData & data, int i, std::string line) {

	std::regex e("^>.*$");

	if (std::regex_match(line, e)) {
		line.erase(0, 1);

		return std::unique_ptr<Action>(new PushLabelToStack(line));
	}
	else {
		return std::unique_ptr<Action>(nullptr);
	}

}