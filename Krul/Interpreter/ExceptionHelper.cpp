#include "pch.h"
#include "ExceptionHelper.h"

void ExceptionHelper::StackContainsEnoughArguments(int n, const MemoryData& data, const std::string& functionName, int lineNumber) {
	if (data.stack.size() < n) {
		std::string msg = "Runtime Error: " + functionName + 
			" called on stack, with to few arguments. On line number " + 
			std::to_string(lineNumber) + ".";
		throw std::exception(msg.c_str());
	}
}

void ExceptionHelper::ValueIsLineNumberType(const std::string& s, const std::string& functionName, int lineNumber) {
	std::regex e("^\\|\\d*$");

	if (!std::regex_match(s, e)) {
		std::string msg = "Runtime Error: " + functionName + 
			" called on a non linenumber value (doesn't start with a pipe). On line number " + 
			std::to_string(lineNumber) + ".";
		throw std::exception(msg.c_str());
	}
}

void ExceptionHelper::VariableIsDeclared(const std::string& s, const MemoryData& data, const std::string& functionName, int lineNumber) {
	if (data.variables.find(s) == data.variables.end()) {
		std::string msg = "Runtime Error: " + functionName +
			" called with undeclared variable name. On line number " + 
			std::to_string(lineNumber) + ".";
		throw std::exception(msg.c_str());
	}
}

void ExceptionHelper::LabelIsDeclared(const std::string& s, const MemoryData& data, const std::string& functionName, int lineNumber) {
	if (data.labels.find(s) == data.labels.end()) {
		std::string msg = "Runtime Error: " + functionName + 
			" called with undeclared label name. On line number " + 
			std::to_string(lineNumber) + ".";
		throw std::exception(msg.c_str());
	}
}

int ExceptionHelper::SecureConvertToInt(const std::string& s, const std::string& functionName, int lineNumber) {
	int number;
	try {
		number = std::stoi(s);
	} catch (std::exception e) {
		std::string msg = "Runtime Error: " + functionName + 
			" called on a non number value. On line number " + 
			std::to_string(lineNumber) + ".";
		throw std::exception(msg.c_str());
	}
	return number;
}
