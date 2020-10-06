#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <map>
#include "Action.h"

class Interpreter
{
private:
	std::vector< std::unique_ptr<Action> > actions;

	std::vector<std::string> stack;
	std::vector<std::string> callStack;
	std::map<std::string, int> dingen;

	void Parse(std::string code);
	void Execute();


public:
	std::string Interpret(std::string code);
};

