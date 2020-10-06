#include "pch.h"
#include "../Interpreter/AddNumbersFromStack.h"
#include "../Interpreter/SubtractNumbersFromStack.h"
#include "../Interpreter/MultiplyNumbersFromStack.h"
#include "../Interpreter/DivideNumbersFromStack.h"
#include "../Interpreter/ModuloNumbersFromStack.h"
#include "../Interpreter/NegateNumberFromStack.h"
#include "../Interpreter/MakeAbsoluteNumberFromStack.h"
#include "../Interpreter/IncrementNumberFromStack.h"
#include "../Interpreter/DecrementNumberFromStack.h"

TEST(Integer_DoTests, Add_DoTest) {
	std::vector<std::string> stack;
	stack.push_back("4");
	stack.push_back("2");

	AddNumbersFromStack action;
	action.Do(stack);

	ASSERT_EQ(stack.at(0), "6");
}

TEST(Integer_DoTests, Sub_DoTest) {
	std::vector<std::string> stack;
	stack.push_back("3");
	stack.push_back("5");

	SubtractNumbersFromStack action;
	action.Do(stack);

	ASSERT_EQ(stack.at(0), "2");
}

TEST(Integer_DoTests, Mul_DoTest) {
	std::vector<std::string> stack;
	stack.push_back("4");
	stack.push_back("2");

	MultiplyNumbersFromStack action;
	action.Do(stack);

	ASSERT_EQ(stack.at(0), "8");
}

TEST(Integer_DoTests, Div_DoTest) {
	std::vector<std::string> stack;
	stack.push_back("2");
	stack.push_back("8");

	DivideNumbersFromStack action;
	action.Do(stack);

	ASSERT_EQ(stack.at(0), "4");
}

TEST(Integer_DoTests, Mod_DoTest) {
	std::vector<std::string> stack;
	stack.push_back("5");
	stack.push_back("2");

	ModuloNumbersFromStack action;
	action.Do(stack);

	ASSERT_EQ(stack.at(0), "1");
}

TEST(Integer_DoTests, Neg_DoTest) {
	std::vector<std::string> stack;
	stack.push_back("4");

	NegateNumberFromStack action;
	action.Do(stack);

	ASSERT_EQ(stack.at(0), "-4");
}

TEST(Integer_DoTests, Abs_DoTest) {
	std::vector<std::string> stack;
	stack.push_back("4");

	MakeAbsoluteNumberFromStack action;
	action.Do(stack);

	ASSERT_EQ(stack.at(0), "4");
}

TEST(Integer_DoTests, Inc_DoTest) {
	std::vector<std::string> stack;
	stack.push_back("4");

	IncrementNumberFromStack action;
	action.Do(stack);

	ASSERT_EQ(stack.at(0), "5");
}

TEST(Integer_DoTests, Dec_DoTest) {
	std::vector<std::string> stack;
	stack.push_back("4");

	DecrementNumberFromStack action;
	action.Do(stack);

	ASSERT_EQ(stack.at(0), "3");
}