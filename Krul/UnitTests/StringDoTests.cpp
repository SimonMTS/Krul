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
    MemoryData data;
    
    data.stack.push_back("some string");

    DuplicateStringFromStack action;
    action.Do(data, 0);

    ASSERT_EQ(data.stack.at(0), "some string");
    ASSERT_EQ(data.stack.at(1), "some string");
}

TEST(String_DoTests, Rev_DoTest) {
    MemoryData data;
    
    data.stack.push_back("some string");

    ReverseStringFromStack action;
    action.Do(data, 0);

    ASSERT_EQ(data.stack.at(0), std::string{ "gnirts emos" });
}

TEST(String_DoTests, Slc_1_DoTest) {
    MemoryData data;
    
    data.stack.push_back("123456789");
    data.stack.push_back("0");
    data.stack.push_back("2");

    SubstringStringFromStack action;
    action.Do(data, 0);

    ASSERT_EQ(data.stack.at(0), "12");
}

TEST(String_DoTests, Slc_2_DoTest) {
    MemoryData data;

    data.stack.push_back("123456789");
    data.stack.push_back("2");
    data.stack.push_back("4");

    SubstringStringFromStack action;
    action.Do(data, 0);

    ASSERT_EQ(data.stack.at(0), "34");
}

TEST(String_DoTests, Idx_DoTest) {
    MemoryData data;
    
    data.stack.push_back("some string");
    data.stack.push_back("3");

    IndexStringFromStack action;
    action.Do(data, 0);

    ASSERT_EQ(data.stack.at(0), "e");
}

TEST(String_DoTests, Cat_DoTest) {
    MemoryData data;
    
    data.stack.push_back("some ");
    data.stack.push_back("string");

    ConcatenateStringFromStack action;
    action.Do(data, 0);

    ASSERT_EQ(data.stack.at(0), "some string");
}

TEST(String_DoTests, Len_DoTest) {
    MemoryData data;
    
    data.stack.push_back("some string");

    GetLengthOfStringFromStack action;
    action.Do(data, 0);

    ASSERT_EQ(data.stack.at(0), "11");
}

TEST(String_DoTests, Rot_DoTest) {
    MemoryData data;
    
    data.stack.push_back("Hello World");

    RotateStringFromStack action;
    action.Do(data, 0);

    ASSERT_EQ(data.stack.at(0), "Uryyb Jbeyq");
}

TEST(String_DoTests, Enl_DoTest) {
    MemoryData data;
    
    data.stack.push_back("some string");

    AddNewLineToStringFromStack action;
    action.Do(data, 0);

    ASSERT_EQ(data.stack.at(0), "some string\n");
}