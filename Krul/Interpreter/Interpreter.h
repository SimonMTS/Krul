#pragma once
#include <sstream>
#include <iostream>
#include <map>
#include "Action.h"

class Interpreter
{
private:
	std::vector<std::unique_ptr<Action>> actions;
	MemoryData data;

	void Parse(const std::string& code);
	void Execute();
	
public:
	std::string Interpret(const std::string& code);
	bool Ended() const;
};

