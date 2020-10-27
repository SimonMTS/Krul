#pragma once
#include <sstream>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <utility>
#include <vector>
#include "Action.h"
using std::string;
using std::unique_ptr;
using std::vector;

class Interpreter {
private:
    vector<unique_ptr<Action>> actions;
    MemoryData data;

    void Parse(const string& code);
    void Execute();

public:
    string Interpret(const string& code);
    bool Ended() const;
};
