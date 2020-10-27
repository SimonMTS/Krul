#pragma once
#include <string>
#include <regex>
#include <iostream>
#include <map>
#include "MemoryData.h"
#include "ExceptionHelper.h"

class Action
{
public:
	static std::vector<std::shared_ptr<std::unique_ptr<Action>(*)(MemoryData&, int, const std::string&)>> matchFunctions;
	static void Populate();
	static void PopulateSingle(std::unique_ptr<Action>(matcher)(MemoryData&, int, const std::string&));

	static std::unique_ptr<Action> Match(MemoryData& data, int i, const std::string& line);

	virtual int Do(MemoryData&, int) = 0;
	virtual ~Action() = default;
};

