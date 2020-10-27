#include "pch.h"
#include "SubtractNumbersFromStack.h"

int SubtractNumbersFromStack::Do(MemoryData& data, int i) {
    ExceptionHelper::StackContainsEnoughArguments(2, data, "SubtractNumbersFromStack", i + 1);

    int number1 = ExceptionHelper::SecureConvertToInt(data.stack.back(), "SubtractNumbersFromStack", i + 1);
    data.stack.pop_back();

    int number2 = ExceptionHelper::SecureConvertToInt(data.stack.back(), "SubtractNumbersFromStack", i + 1);
    data.stack.pop_back();

    int res = number2 - number1;

    data.stack.push_back(std::to_string(res));

    return i;
}

std::unique_ptr<Action> SubtractNumbersFromStack::Match(MemoryData& data, int i, const std::string& line) {
    std::regex e("^sub");

    if (std::regex_match(line, e)) {
        return std::unique_ptr<Action>(new SubtractNumbersFromStack());
    } else {
        return std::unique_ptr<Action>(nullptr);
    }
}
