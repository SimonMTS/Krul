#include "pch.h"
#include "DivideNumbersFromStack.h"

int DivideNumbersFromStack::Do(MemoryData& data, int i) {
    ExceptionHelper::StackContainsEnoughArguments(2, data, "DivideNumbersFromStack", i + 1);

    int number2 = ExceptionHelper::SecureConvertToInt(data.stack.back(), "DivideNumbersFromStack", i + 1);
    data.stack.pop_back();

    int number1 = ExceptionHelper::SecureConvertToInt(data.stack.back(), "DivideNumbersFromStack", i + 1);
    data.stack.pop_back();

    // todo maybe check if number2 != 0. to avoid div by zero error
    int res = number1 / number2;

    data.stack.push_back(std::to_string(res));

    return i;
}

std::unique_ptr<Action> DivideNumbersFromStack::Match(MemoryData& data, int i, const std::string& line) {
    std::regex e("^div$");

    if (std::regex_match(line, e)) {
        return std::unique_ptr<Action>(new DivideNumbersFromStack());
    } else {
        return std::unique_ptr<Action>(nullptr);
    }
}
