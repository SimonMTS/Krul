#pragma once
#include <string>
#include <vector>
#include <map>
using std::string;
using std::vector;
using std::map;

struct MemoryData {
    vector<string> stack;
    vector<string> callStack;
    map<string, string> variables;
    map<string, int> labels;
    bool ended = false;
};
