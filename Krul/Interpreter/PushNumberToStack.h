#pragma once
#include "Action.h"

class PushNumberToStack : public Action {
public:
    PushNumberToStack(std::string n);
    int Do(MemoryData&, int) override;
    static std::unique_ptr<Action> Match(MemoryData& data, int i, const std::string& line);

private:
    std::string number;
};

