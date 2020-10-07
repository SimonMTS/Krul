#pragma once
#include "Action.h"
class PushStringToStack :
    public Action
{
public:
    PushStringToStack(std::string s);
    int Do(MemoryData&, int) override;
    static std::unique_ptr<Action> Match(MemoryData& data, int i, std::string line);

private:
    std::string string;
};

