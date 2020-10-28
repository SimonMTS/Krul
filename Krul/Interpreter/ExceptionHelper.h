#pragma once
#include <string>
#include <regex>
#include "MemoryData.h"
using std::string;

class ExceptionHelper {
public:
    static void StackContainsEnoughArguments(
        int n, const MemoryData& data,
        const string& functionName, int lineNumber);
    static void CallStackContainsEnoughArguments(
        int n, const MemoryData& data,
        const string& functionName, int lineNumber);
    static void ValueIsLineNumberType(
        const string& s, const string& functionName,
        int lineNumber);

    static void VariableIsDeclared(
        const string& s, const MemoryData& data,
        const string& functionName, int lineNumber);
    static void LabelIsDeclared(
        const string& s, const MemoryData& data,
        const string& functionName, int lineNumber);

    static int SecureConvertToInt(
        const string& s, const string& functionName,
        int lineNumber);
};
