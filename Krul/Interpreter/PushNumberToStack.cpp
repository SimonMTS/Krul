#include "pch.h"
#include "PushNumberToStack.h"

PushNumberToStack::PushNumberToStack(std::string n) {
    number = n;
}

int PushNumberToStack::Do(MemoryData& data, int i) {
    data.stack.push_back(number);

    return i;
}

std::unique_ptr<Action> PushNumberToStack::Match(MemoryData& data, int i, const std::string& line) {
    std::regex e("^\\d*$");

    if (std::regex_match(line, e)) {
        return std::unique_ptr<Action>( new PushNumberToStack(line) );
    } else {
        return std::unique_ptr<Action>(nullptr);
    }
}
