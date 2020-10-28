#include <exception>
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
using std::exception;
using std::string;

TEST(Integer_DoTests, Add_pos_DoTest) {
    MemoryData data;
    data.stack.push_back("4");
    data.stack.push_back("2");

    AddNumbersFromStack action;
    action.Do(data, 0);

    ASSERT_EQ(data.stack.at(0), "6");
}

TEST(Integer_DoTests, Add_neg_DoTest) {
    MemoryData data;
    data.stack.push_back("a");
    data.stack.push_back("2");

    AddNumbersFromStack action;
    try {
        action.Do(data, 0);
        ASSERT_EQ(true, false);
    } catch (const exception& e) {
        string msg = e.what();
        string shouldBe = "Runtime Error: AddNumbersFromStack called on a non number value. On line number 1.";
        ASSERT_EQ(msg, shouldBe);
    }
}

TEST(Integer_DoTests, Sub_pos_DoTest) {
    MemoryData data;
    data.stack.push_back("5");
    data.stack.push_back("3");

    SubtractNumbersFromStack action;
    action.Do(data, 0);

    ASSERT_EQ(data.stack.at(0), "2");
}

TEST(Integer_DoTests, Sub_neg_DoTest) {
    MemoryData data;
    data.stack.push_back("a");
    data.stack.push_back("3");

    SubtractNumbersFromStack action;
    try {
        action.Do(data, 0);
        ASSERT_EQ(true, false);
    } catch (const exception& e) {
        string msg = e.what();
        string shouldBe = "Runtime Error: SubtractNumbersFromStack called on a non number value. On line number 1.";
        ASSERT_EQ(msg, shouldBe);
    }
}

TEST(Integer_DoTests, Mul_pos_DoTest) {
    MemoryData data;
    data.stack.push_back("4");
    data.stack.push_back("2");

    MultiplyNumbersFromStack action;
    action.Do(data, 0);

    ASSERT_EQ(data.stack.at(0), "8");
}

TEST(Integer_DoTests, Mul_neg_DoTest) {
    MemoryData data;
    data.stack.push_back("a");
    data.stack.push_back("2");

    MultiplyNumbersFromStack action;
    try {
        action.Do(data, 0);
        ASSERT_EQ(true, false);
    } catch (const exception& e) {
        string msg = e.what();
        string shouldBe = "Runtime Error: MultiplyNumbersFromStack called on a non number value. On line number 1.";
        ASSERT_EQ(msg, shouldBe);
    }
}

TEST(Integer_DoTests, Div_pos_DoTest) {
    MemoryData data;
    data.stack.push_back("8");
    data.stack.push_back("2");

    DivideNumbersFromStack action;
    action.Do(data, 0);

    ASSERT_EQ(data.stack.at(0), "4");
}

TEST(Integer_DoTests, Div_neg_DoTest) {
    MemoryData data;
    data.stack.push_back("a");
    data.stack.push_back("2");

    DivideNumbersFromStack action;
    try {
        action.Do(data, 0);
        ASSERT_EQ(true, false);
    } catch (const exception& e) {
        string msg = e.what();
        string shouldBe = "Runtime Error: DivideNumbersFromStack called on a non number value. On line number 1.";
        ASSERT_EQ(msg, shouldBe);
    }
}

TEST(Integer_DoTests, Mod_pos_DoTest) {
    MemoryData data;
    data.stack.push_back("5");
    data.stack.push_back("2");

    ModuloNumbersFromStack action;
    action.Do(data, 0);

    ASSERT_EQ(data.stack.at(0), "1");
}

TEST(Integer_DoTests, Mod_neg_DoTest) {
    MemoryData data;
    data.stack.push_back("a");
    data.stack.push_back("2");

    ModuloNumbersFromStack action;
    try {
        action.Do(data, 0);
        ASSERT_EQ(true, false);
    } catch (const exception& e) {
        string msg = e.what();
        string shouldBe = "Runtime Error: ModuloNumbersFromStack called on a non number value. On line number 1.";
        ASSERT_EQ(msg, shouldBe);
    }
}

TEST(Integer_DoTests, Neg_pos_DoTest) {
    MemoryData data;
    data.stack.push_back("4");

    NegateNumberFromStack action;
    action.Do(data, 0);

    ASSERT_EQ(data.stack.at(0), "-4");
}

TEST(Integer_DoTests, Neg_neg_DoTest) {
    MemoryData data;
    data.stack.push_back("a");

    NegateNumberFromStack action;
    try {
        action.Do(data, 0);
        ASSERT_EQ(true, false);
    } catch (const exception& e) {
        string msg = e.what();
        string shouldBe = "Runtime Error: NegateNumberFromStack called on a non number value. On line number 1.";
        ASSERT_EQ(msg, shouldBe);
    }
}

TEST(Integer_DoTests, Abs_pos_DoTest) {
    MemoryData data;
    data.stack.push_back("4");

    MakeAbsoluteNumberFromStack action;
    action.Do(data, 0);

    ASSERT_EQ(data.stack.at(0), "4");
}

TEST(Integer_DoTests, Abs_neg_DoTest) {
    MemoryData data;
    data.stack.push_back("a");

    MakeAbsoluteNumberFromStack action;
    try {
        action.Do(data, 0);
        ASSERT_EQ(true, false);
    } catch (const exception& e) {
        string msg = e.what();
        string shouldBe = "Runtime Error: MakeAbsoluteNumberFromStack called on a non number value. On line number 1.";
        ASSERT_EQ(msg, shouldBe);
    }
}

TEST(Integer_DoTests, Inc_pos_DoTest) {
    MemoryData data;
    data.stack.push_back("4");

    IncrementNumberFromStack action;
    action.Do(data, 0);

    ASSERT_EQ(data.stack.at(0), "5");
}

TEST(Integer_DoTests, Inc_neg_DoTest) {
    MemoryData data;
    data.stack.push_back("a");

    IncrementNumberFromStack action;
    try {
        action.Do(data, 0);
        ASSERT_EQ(true, false);
    } catch (const exception& e) {
        string msg = e.what();
        string shouldBe = "Runtime Error: IncrementNumberFromStack called on a non number value. On line number 1.";
        ASSERT_EQ(msg, shouldBe);
    }
}

TEST(Integer_DoTests, Dec_pos_DoTest) {
    MemoryData data;
    data.stack.push_back("4");

    DecrementNumberFromStack action;
    action.Do(data, 0);

    ASSERT_EQ(data.stack.at(0), "3");
}

TEST(Integer_DoTests, Dec_neg_DoTest) {
    MemoryData data;
    data.stack.push_back("a");

    DecrementNumberFromStack action;
    try {
        action.Do(data, 0);
        ASSERT_EQ(true, false);
    } catch (const exception& e) {
        string msg = e.what();
        string shouldBe = "Runtime Error: DecrementNumberFromStack called on a non number value. On line number 1.";
        ASSERT_EQ(msg, shouldBe);
    }
}