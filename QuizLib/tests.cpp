#include <iostream>
#include <sstream>
#include <string>
#include <cassert>
#include <Windows.h>
#include "QuizLib.h"

#undef max

static std::stringbuf* oldBuffer = nullptr;
static std::stringbuf fakeBuffer;

void setInput(const std::string& data)
{
    if (oldBuffer == nullptr)
    {
        oldBuffer = static_cast<std::stringbuf*>(std::cin.rdbuf());
    }
    fakeBuffer.str(data);
    std::cin.rdbuf(&fakeBuffer);
    std::cin.clear();
}

void resetCin()
{
    if (oldBuffer)
    {
        std::cin.rdbuf(oldBuffer);
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void testConstructor()
{
    Quiz q;
    assert(q.getScore() == 0);
    std::cout << "Constructor PASSED\n";
}

void testAddQuestion()
{
    Quiz q;
    q.addQuestion("Òåñò?", { "À","Á" }, 0);
    std::cout << "AddQuestion PASSED (visual check not needed)\n";
}

void testStartCorrect()
{
    Quiz q;
    q.addQuestion("2+2=?", { "3","4","5" }, 1);
    setInput("2\n");
    q.start();
    assert(q.getScore() == 1);
    std::cout << "StartCorrect PASSED\n";
    resetCin();
}

void testStartWrong()
{
    Quiz q;
    q.addQuestion("2+2=?", { "3","4","5" }, 1);
    setInput("1\n");
    q.start();
    assert(q.getScore() == 0);
    std::cout << "StartWrong PASSED\n";
    resetCin();
}

void testReset()
{
    Quiz q;
    q.addQuestion("?", { "A" }, 0);
    setInput("1\n");
    q.start();
    q.reset();
    assert(q.getScore() == 0);
    std::cout << "Reset PASSED\n";
    resetCin();
}

void testInputInt()
{
    setInput("abc\n789\n");
    int x = Quiz::inputInt("×èñëî: ");
    assert(x == 789);
    std::cout << "InputInt PASSED\n";
    resetCin();
}

void testInputString()
{
    setInput("   ïðèâåò ìèð   \n");
    std::string s = Quiz::inputString("Ñòðîêà: ");
    assert(s == "ïðèâåò ìèð");
    std::cout << "InputString PASSED\n";
    resetCin();
}

//int main()
//{
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    testConstructor();
//    testAddQuestion();
//    testStartCorrect();
//    testStartWrong();
//    testReset();
//    testInputInt();
//    testInputString();
//
//    std::cout << "\nÂÑÅ ÒÅÑÒÛ ÏÐÎØËÈ ÓÑÏÅØÍÎ\n";
//    return 0;
//}