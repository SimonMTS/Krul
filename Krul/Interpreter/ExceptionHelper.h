#pragma once
#include <string>
#include <regex>
#include "MemoryData.h"

class ExceptionHelper {
public:
    static void StackContainsEnoughArguments(int n, MemoryData& data, std::string functionName, int lineNumber);
    static void ValueIsLineNumberType(std::string s, std::string functionName, int lineNumber);

    static void VariableIsDeclared(std::string s, MemoryData& data, std::string functionName, int lineNumber);
    static void LabelIsDeclared(std::string s, MemoryData& data, std::string functionName, int lineNumber);

    static int SecureConvertToInt(std::string s, std::string functionName, int lineNumber);
};
