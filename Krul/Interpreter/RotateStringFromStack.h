#pragma once
#include "Action.h"
class RotateStringFromStack :
    public Action
{
public:
    void Do(std::vector<std::string>&) override;
    static std::unique_ptr<Action> Match(std::string line);
private:
    std::string rot13(std::string input);
};

