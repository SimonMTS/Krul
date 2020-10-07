#include "pch.h"
#include "RotateStringFromStack.h"

int RotateStringFromStack::Do(MemoryData& data, int i) {
	std::string string = data.stack.back();
	data.stack.pop_back();

	std::string res = rot13(string);

	data.stack.push_back(res);

	return i;
}

std::unique_ptr<Action> RotateStringFromStack::Match(MemoryData & data, int i, std::string line) {
	std::regex e("^rot$");

	if (std::regex_match(line, e)) {
		return std::unique_ptr<Action>(new RotateStringFromStack());
	}
	else {
		return std::unique_ptr<Action>(nullptr);
	}
}

std::string RotateStringFromStack::rot13(std::string input) {

	for (std::string::size_type len = input.length(), idx = 0; idx != len; ++idx) {
		if (input[idx] >= 'a' && input[idx] <= 'm') {
			input[idx] = input[idx] + 13;
		}
		else if (input[idx] >= 'n' && input[idx] <= 'z') {
			input[idx] = input[idx] - 13;
		}
		else if (input[idx] >= 'A' && input[idx] <= 'M') {
			input[idx] = input[idx] + 13;
		}
		else if (input[idx] >= 'N' && input[idx] <= 'Z') {
			input[idx] = input[idx] - 13;
		}
	}

	return input;

}