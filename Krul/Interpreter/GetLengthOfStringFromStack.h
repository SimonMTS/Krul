#pragma once
#include "Action.h"
class GetLengthOfStringFromStack :
    public Action
{
public:
    int Do(MemoryData&, int) override;
    static std::unique_ptr<Action> Match(MemoryData& data, int i, std::string line);
};

