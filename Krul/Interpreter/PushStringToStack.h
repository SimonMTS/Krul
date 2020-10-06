#pragma once
#include "Action.h"
class PushStringToStack :
    public Action
{
public:
    PushStringToStack(std::string s);
    void Do(std::vector<std::string>&) override;
    static std::unique_ptr<Action> Match(std::string line);

private:
    std::string string;
};

