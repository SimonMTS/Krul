#include "pch.h"
#include "MakeAbsoluteNumberFromStack.h"

int MakeAbsoluteNumberFromStack::Do(MemoryData& data, int i) {
    ExceptionHelper::StackContainsEnoughArguments(1, data, "MakeAbsoluteNumberFromStack", i + 1);

    int number = ExceptionHelper::SecureConvertToInt(data.stack.back(), "MakeAbsoluteNumberFromStack", i + 1);
    data.stack.pop_back();

    int res = std::abs(number);

    data.stack.push_back(std::to_string(res));

    return i;
}

std::unique_ptr<Action> MakeAbsoluteNumberFromStack::Match(MemoryData& data, int i, const std::string& line) {
    std::regex e("^abs$");

    if (std::regex_match(line, e)) {
        return std::unique_ptr<Action>(new MakeAbsoluteNumberFromStack());
    } else {
        return std::unique_ptr<Action>(nullptr);
    }
}
