#include "pch.h"
#include "SubstringStringFromStack.h"

int SubstringStringFromStack::Do(MemoryData& data, int i) {
    ExceptionHelper::StackContainsEnoughArguments(3, data, "SubstringStringFromStack", i + 1);

    size_t to = ExceptionHelper::SecureConvertToInt(data.stack.back(), "SubstringStringFromStack", i + 1);
    data.stack.pop_back();

    size_t from = ExceptionHelper::SecureConvertToInt(data.stack.back(), "SubstringStringFromStack", i + 1);
    data.stack.pop_back();

    std::string value = data.stack.back();
    data.stack.pop_back();

    std::string res = value.substr(from, to - from);

    data.stack.push_back(res);

    return i;
}

std::unique_ptr<Action> SubstringStringFromStack::Match(MemoryData& data, int i, const std::string& line) {
    std::regex e("^slc$");

    if (std::regex_match(line, e)) {
        return std::unique_ptr<Action>(new SubstringStringFromStack());
    } else {
        return std::unique_ptr<Action>(nullptr);
    }
}
