#include "pch.h"
#include "AssignVariableFromStack.h"

AssignVariableFromStack::AssignVariableFromStack(std::string n) {
    name = n;
}

int AssignVariableFromStack::Do(MemoryData& data, int i) {
    ExceptionHelper::StackContainsEnoughArguments(1, data, "AssignVariableFromStack", i + 1);

    std::string string = data.stack.back();
    data.stack.pop_back();

    data.variables[name] = string;

    return i;
}

std::unique_ptr<Action> AssignVariableFromStack::Match(MemoryData& data, int i, const std::string& line) {
    std::regex e("^=.*$");

    if (std::regex_match(line, e)) {
        std::string string = line;
        string.erase(0, 1);

        return std::unique_ptr<Action>(new AssignVariableFromStack(string));
    } else {
        return std::unique_ptr<Action>(nullptr);
    }
}