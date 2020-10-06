#pragma once
#include "Action.h"

class PushNumberToStack :
    public Action
{
public:
    PushNumberToStack(std::string n);
    void Do(std::vector<std::string>&) override;
    static std::unique_ptr<Action> Match(std::string line);

private:
    std::string number;
};

