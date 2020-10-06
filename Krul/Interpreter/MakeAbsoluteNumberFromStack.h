#pragma once
#include "Action.h"

class MakeAbsoluteNumberFromStack :
    public Action
{
public:
    void Do(std::vector<std::string>&) override;
    static std::unique_ptr<Action> Match(std::string line);
};

