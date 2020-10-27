#pragma once
#include "Action.h"

class AssignVariableFromStack : public Action {
public:
    AssignVariableFromStack(std::string n);
    int Do(MemoryData&, int) override;
    static std::unique_ptr<Action> Match(MemoryData& data, int i, std::string line);

private:
    std::string name;
};
