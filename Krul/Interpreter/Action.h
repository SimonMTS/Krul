#pragma once
#include <string>
#include <regex>
#include <iostream>
#include <vector>
#include <map>
#include <memory>
#include "MemoryData.h"
#include "ExceptionHelper.h"
using std::string;
using std::vector;
using std::shared_ptr;
using std::unique_ptr;

class Action {
public:
    static vector<
        shared_ptr<unique_ptr<Action>(*)(MemoryData&, int, const string&)>
        > matchFunctions;
    static void Populate();
    static void PopulateSingle(
        unique_ptr<Action>(matcher)(MemoryData&, int, const string&));

    static unique_ptr<Action> Match(
        MemoryData& data, int i, const string& line);

    virtual int Do(MemoryData&, int) = 0;
    virtual ~Action() = default;
};
