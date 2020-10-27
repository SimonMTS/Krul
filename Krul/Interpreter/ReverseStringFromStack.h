#pragma once
#include "Action.h"

class ReverseStringFromStack : public Action {
public:
    int Do(MemoryData&, int) override;
    static std::unique_ptr<Action> Match(MemoryData& data, int i, const std::string& line);
};

