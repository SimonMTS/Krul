#include "pch.h"
#include "GoToLine.h"

int GoToLine::Do(MemoryData& data, int i) {
    ExceptionHelper::StackContainsEnoughArguments(1, data, "GoToLine", i + 1);

    std::string label_value_str = data.stack.back();
    ExceptionHelper::ValueIsLineNumberType(label_value_str, "GoToLine", i + 1);
    data.stack.pop_back();

    label_value_str.erase(0, 1);
    int label_value = ExceptionHelper::SecureConvertToInt(label_value_str, "GoToLine", i + 1);

    return label_value;
}

std::unique_ptr<Action> GoToLine::Match(MemoryData& data, int i, const std::string& line) {
    std::regex e("^gto$");

    if (std::regex_match(line, e)) {
        return std::unique_ptr<Action>(new GoToLine());
    } else {
        return std::unique_ptr<Action>(nullptr);
    }
}
