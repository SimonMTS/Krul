#include "pch.h"
#include "ExceptionHelper.h"
using std::string;
using std::to_string;
using std::exception;
using std::regex;
using std::regex_match;

void ExceptionHelper::StackContainsEnoughArguments(
    int n, const MemoryData& data,
    const string& functionName, int lineNumber) {
    if (data.stack.size() < n) {
        throw exception(("Runtime Error: " + functionName +
            " called on stack, with to few arguments. On line number " +
            to_string(lineNumber) + ".").c_str());
    }
}

void ExceptionHelper::CallStackContainsEnoughArguments(
    int n, const MemoryData& data,
    const string& functionName, int lineNumber) {
    if (data.callStack.size() < n) {
        throw exception(("Runtime Error: " + functionName +
            " called on callStack, with to few arguments. On line number " +
            to_string(lineNumber) + ".").c_str());
    }
}

void ExceptionHelper::ValueIsLineNumberType(
    const string& s, const string& functionName,
    int lineNumber) {
    regex expression("^\\|\\d*$");

    if (!regex_match(s, expression)) {
        throw exception(("Runtime Error: " + functionName +
            " called on a non linenumber value. On line number " +
            to_string(lineNumber) + ".").c_str());
    }
}

void ExceptionHelper::VariableIsDeclared(
    const string& s, const MemoryData& data,
    const string& functionName, int lineNumber) {
    if (data.variables.find(s) == data.variables.end()) {
        throw exception(("Runtime Error: " + functionName +
            " called with undeclared variable name. On line number " +
            to_string(lineNumber) + ".").c_str());
    }
}

void ExceptionHelper::LabelIsDeclared(
    const string& s, const MemoryData& data,
    const string& functionName, int lineNumber) {
    if (data.labels.find(s) == data.labels.end()) {
        throw exception(("Runtime Error: " + functionName +
            " called with undeclared label name. On line number " +
            to_string(lineNumber) + ".").c_str());
    }
}

int ExceptionHelper::SecureConvertToInt(
    const string& s, const string& functionName,
    int lineNumber) {
    try {
        return std::stoi(s);
    } catch (const exception& e) {
        throw exception(("Runtime Error: " + functionName +
            " called on a non number value. On line number " +
            to_string(lineNumber) + ".").c_str());
    }
}
