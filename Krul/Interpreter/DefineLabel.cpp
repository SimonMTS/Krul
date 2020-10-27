#include "pch.h"
#include "DefineLabel.h"

DefineLabel::DefineLabel(std::string n) {
	name = n;
}

int DefineLabel::Do(MemoryData& data, int i) {
	data.labels[name] = i;

	return i;
}

std::unique_ptr<Action> DefineLabel::Match(MemoryData & data, int i, std::string line) {
	std::regex e(":.*$");

	if (std::regex_match(line, e)) {
		line.erase(0, 1);

		data.labels[line] = i;

		return std::unique_ptr<Action>(new DefineLabel(line));
	} else {
		return std::unique_ptr<Action>(nullptr);
	}
}
