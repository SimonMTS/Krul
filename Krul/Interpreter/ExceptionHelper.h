#pragma once
#include <string>
#include <regex>
#include "MemoryData.h"

class ExceptionHelper {
public:
    static void StackContainsEnoughArguments(int n, const MemoryData& data, const std::string& functionName, int lineNumber);
    static void ValueIsLineNumberType(const std::string& s, const std::string& functionName, int lineNumber);

    static void VariableIsDeclared(const std::string& s, const MemoryData& data, const std::string& functionName, int lineNumber);
    static void LabelIsDeclared(const std::string& s, const MemoryData& data, const std::string& functionName, int lineNumber);

    static int SecureConvertToInt(const std::string& s, const std::string& functionName, int lineNumber);
};
