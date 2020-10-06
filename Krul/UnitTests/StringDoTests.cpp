#include "pch.h"
#include "../Interpreter/DuplicateStringFromStack.h"
#include "../Interpreter/AddNewLineToStringFromStack.h"
#include "../Interpreter/RotateStringFromStack.h"
#include "../Interpreter/GetLengthOfStringFromStack.h"
#include "../Interpreter/ConcatenateStringFromStack.h"
#include "../Interpreter/IndexStringFromStack.h"
#include "../Interpreter/SubstringStringFromStack.h"
#include "../Interpreter/ReverseStringFromStack.h"

TEST(String_DoTests, Dup_DoTest) {
	std::vector<std::string> stack;
	stack.push_back("some string");

	DuplicateStringFromStack action;
	action.Do(stack);

	ASSERT_EQ(stack.at(0), "some string");
	ASSERT_EQ(stack.at(1), "some string");
}

TEST(String_DoTests, Rev_DoTest) {
	std::vector<std::string> stack;
	stack.push_back("some string");

	ReverseStringFromStack action;
	action.Do(stack);

	ASSERT_EQ(stack.at(0), "gnirts emos");
}

TEST(String_DoTests, Slc_DoTest) {
	std::vector<std::string> stack;
	stack.push_back("some string");
	stack.push_back("2");
	stack.push_back("9");

	SubstringStringFromStack action;
	action.Do(stack);

	ASSERT_EQ(stack.at(0), "me stri");
}

TEST(String_DoTests, Idx_DoTest) {
	std::vector<std::string> stack;
	stack.push_back("some string");
	stack.push_back("3");

	IndexStringFromStack action;
	action.Do(stack);

	ASSERT_EQ(stack.at(0), "e");
}

TEST(String_DoTests, Cat_DoTest) {
	std::vector<std::string> stack;
	stack.push_back("string");
	stack.push_back("some ");

	ConcatenateStringFromStack action;
	action.Do(stack);

	ASSERT_EQ(stack.at(0), "some string");
}

TEST(String_DoTests, Len_DoTest) {
	std::vector<std::string> stack;
	stack.push_back("some string");

	GetLengthOfStringFromStack action;
	action.Do(stack);

	ASSERT_EQ(stack.at(0), "11");
}

TEST(String_DoTests, Rot_DoTest) {
	std::vector<std::string> stack;
	stack.push_back("Hello World");

	RotateStringFromStack action;
	action.Do(stack);

	ASSERT_EQ(stack.at(0), "Uryyb Jbeyq");
}

TEST(String_DoTests, Enl_DoTest) {
	std::vector<std::string> stack;
	stack.push_back("some string");

	AddNewLineToStringFromStack action;
	action.Do(stack);

	ASSERT_EQ(stack.at(0), "some string\n");
}