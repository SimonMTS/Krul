#include <exception>
#include "pch.h"
#include "../Interpreter/DuplicateStringFromStack.h"
#include "../Interpreter/AddNewLineToStringFromStack.h"
#include "../Interpreter/RotateStringFromStack.h"
#include "../Interpreter/GetLengthOfStringFromStack.h"
#include "../Interpreter/ConcatenateStringFromStack.h"
#include "../Interpreter/IndexStringFromStack.h"
#include "../Interpreter/SubstringStringFromStack.h"
#include "../Interpreter/ReverseStringFromStack.h"
using std::exception;
using std::string;

TEST(String_DoTests, Dup_pos_DoTest) {
    MemoryData data;
    
    data.stack.push_back("some string");

    DuplicateStringFromStack action;
    action.Do(data, 0);

    ASSERT_EQ(data.stack.at(0), "some string");
    ASSERT_EQ(data.stack.at(1), "some string");
}
TEST(String_DoTests, Dup_neg_DoTest) {
    MemoryData data;
    
    DuplicateStringFromStack action;
    try {
        action.Do(data, 0);
        ASSERT_EQ(true, false);
    } catch (const exception& e) {
        string msg = e.what();
        string shouldBe = "Runtime Error: DuplicateStringFromStack called on stack, with to few arguments. On line number 1.";
        ASSERT_EQ(msg, shouldBe);
    }
}

TEST(String_DoTests, Rev_pos_DoTest) {
    MemoryData data;
    
    data.stack.push_back("some string");

    ReverseStringFromStack action;
    action.Do(data, 0);

    ASSERT_EQ(data.stack.at(0), std::string{ "gnirts emos" });
}
TEST(String_DoTests, Rev_neg_DoTest) {
    MemoryData data;

    ReverseStringFromStack action;
    try {
        action.Do(data, 0);
        ASSERT_EQ(true, false);
    } catch (const exception& e) {
        string msg = e.what();
        string shouldBe = "Runtime Error: ReverseStringFromStack called on stack, with to few arguments. On line number 1.";
        ASSERT_EQ(msg, shouldBe);
    }
}

TEST(String_DoTests, Slc_pos_1_DoTest) {
    MemoryData data;
    
    data.stack.push_back("123456789");
    data.stack.push_back("0");
    data.stack.push_back("2");

    SubstringStringFromStack action;
    action.Do(data, 0);

    ASSERT_EQ(data.stack.at(0), "12");
}

TEST(String_DoTests, Slc_pos_2_DoTest) {
    MemoryData data;

    data.stack.push_back("123456789");
    data.stack.push_back("2");
    data.stack.push_back("4");

    SubstringStringFromStack action;
    action.Do(data, 0);

    ASSERT_EQ(data.stack.at(0), "34");
}

TEST(String_DoTests, Slc_neg_DoTest) {
    MemoryData data;

    data.stack.push_back("123456789");
    data.stack.push_back("2");

    SubstringStringFromStack action;
    try {
        action.Do(data, 0);
        ASSERT_EQ(true, false);
    } catch (const exception& e) {
        string msg = e.what();
        string shouldBe = "Runtime Error: SubstringStringFromStack called on stack, with to few arguments. On line number 1.";
        ASSERT_EQ(msg, shouldBe);
    }
}

TEST(String_DoTests, Idx_pos_DoTest) {
    MemoryData data;
    
    data.stack.push_back("some string");
    data.stack.push_back("3");

    IndexStringFromStack action;
    action.Do(data, 0);

    ASSERT_EQ(data.stack.at(0), "e");
}
TEST(String_DoTests, Idx_neg_DoTest) {
    MemoryData data;
    
    data.stack.push_back("some string");

    IndexStringFromStack action;
    try {
        action.Do(data, 0);
        ASSERT_EQ(true, false);
    } catch (const exception& e) {
        string msg = e.what();
        string shouldBe = "Runtime Error: IndexStringFromStack called on stack, with to few arguments. On line number 1.";
        ASSERT_EQ(msg, shouldBe);
    }
}

TEST(String_DoTests, Cat_pos_DoTest) {
    MemoryData data;
    
    data.stack.push_back("some ");
    data.stack.push_back("string");

    ConcatenateStringFromStack action;
    action.Do(data, 0);

    ASSERT_EQ(data.stack.at(0), "some string");
}
TEST(String_DoTests, Cat_neg_DoTest) {
    MemoryData data;
    
    data.stack.push_back("some ");

    ConcatenateStringFromStack action;
    try {
        action.Do(data, 0);
        ASSERT_EQ(true, false);
    } catch (const exception& e) {
        string msg = e.what();
        string shouldBe = "Runtime Error: ConcatenateStringFromStack called on stack, with to few arguments. On line number 1.";
        ASSERT_EQ(msg, shouldBe);
    }
}

TEST(String_DoTests, Len_pos_DoTest) {
    MemoryData data;
    
    data.stack.push_back("some string");

    GetLengthOfStringFromStack action;
    action.Do(data, 0);

    ASSERT_EQ(data.stack.at(0), "11");
}
TEST(String_DoTests, Len_neg_DoTest) {
    MemoryData data;
    
    GetLengthOfStringFromStack action;
    try {
        action.Do(data, 0);
        ASSERT_EQ(true, false);
    } catch (const exception& e) {
        string msg = e.what();
        string shouldBe = "Runtime Error: GetLengthOfStringFromStack called on stack, with to few arguments. On line number 1.";
        ASSERT_EQ(msg, shouldBe);
    }
}

TEST(String_DoTests, Rot_pos_DoTest) {
    MemoryData data;
    
    data.stack.push_back("Hello World");

    RotateStringFromStack action;
    action.Do(data, 0);

    ASSERT_EQ(data.stack.at(0), "Uryyb Jbeyq");
}
TEST(String_DoTests, Rot_neg_DoTest) {
    MemoryData data;
    
    RotateStringFromStack action;
    try {
        action.Do(data, 0);
        ASSERT_EQ(true, false);
    } catch (const exception& e) {
        string msg = e.what();
        string shouldBe = "Runtime Error: RotateStringFromStack called on stack, with to few arguments. On line number 1.";
        ASSERT_EQ(msg, shouldBe);
    }
}

TEST(String_DoTests, Enl_pos_DoTest) {
    MemoryData data;
    
    data.stack.push_back("some string");

    AddNewLineToStringFromStack action;
    action.Do(data, 0);

    ASSERT_EQ(data.stack.at(0), "some string\n");
}
TEST(String_DoTests, Enl_neg_DoTest) {
    MemoryData data;
    
    AddNewLineToStringFromStack action;
    try {
        action.Do(data, 0);
        ASSERT_EQ(true, false);
    } catch (const exception& e) {
        string msg = e.what();
        string shouldBe = "Runtime Error: AddNewLineToStringFromStack called on stack, with to few arguments. On line number 1.";
        ASSERT_EQ(msg, shouldBe);
    }
}