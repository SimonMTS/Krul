#pragma once
#include "Action.h"

class GoToLineIfLess : public Action {
public:
    int Do(MemoryData&, int) override;
    static std::unique_ptr<Action> Match(MemoryData& data, int i, const std::string& line);
};

