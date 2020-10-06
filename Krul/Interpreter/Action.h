#pragma once
#include <string>
#include <regex>
#include <iostream>

class Action
{
public:
	static std::vector< std::shared_ptr<std::unique_ptr<Action>(*)(std::string)> > matchFunctions;
	static void Populate();

	static std::unique_ptr<Action> Match(std::string line);

	virtual void Do(std::vector<std::string>&) = 0;
	//virtual ~Action() = 0;
};

