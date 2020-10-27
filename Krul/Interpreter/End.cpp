#include "pch.h"
#include "End.h"

int End::Do(MemoryData& data, int i) {
	data.ended = true;
	return i;
}

std::unique_ptr<Action> End::Match(MemoryData& data, int i, const std::string& line) {
	std::regex e("^end$");

	if (std::regex_match(line, e)) {
		return std::unique_ptr<Action>(new End());
	} else {
		return std::unique_ptr<Action>(nullptr);
	}
}