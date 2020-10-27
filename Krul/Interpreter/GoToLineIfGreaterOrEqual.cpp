#include "pch.h"
#include "GoToLineIfGreaterOrEqual.h"

int GoToLineIfGreaterOrEqual::Do(MemoryData& data, int i) {
    std::string label_value_str = data.stack.back();
    data.stack.pop_back();
    label_value_str.erase(0, 1);
    int label_value = std::stoi(label_value_str);

    int value2 = std::stoi(data.stack.back());
    data.stack.pop_back();

    int value1 = std::stoi(data.stack.back());
    data.stack.pop_back();

    if (value1 >= value2) {
        return label_value;
    } else {
        return i;
    }
}

std::unique_ptr<Action> GoToLineIfGreaterOrEqual::Match(MemoryData& data, int i, const std::string& line) {
    std::regex e("^gge$");

    if (std::regex_match(line, e)) {
        return std::unique_ptr<Action>(new GoToLineIfGreaterOrEqual());
    } else {
        return std::unique_ptr<Action>(nullptr);
    }
}