#pragma once
#include <sstream>
#include <iostream>
#include <map>
#include "Action.h"

class Interpreter
{
private:
	std::vector< std::unique_ptr<Action> > actions;
	MemoryData data;

	void Parse(std::string code);
	void Execute();
	
public:
	std::string Interpret(std::string code);
	bool Ended();
};

