#pragma once
#include <string>
#include <vector>
#include <map>

struct MemoryData {
	std::vector<std::string> stack;
	std::vector<std::string> callStack;
	std::map<std::string, std::string> variables;
	std::map<std::string, int> labels;
	bool ended;
};