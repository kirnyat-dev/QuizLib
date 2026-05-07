#include <iostream>
#include <sstream>
#include <cassert>
#include "QuizLib.h"

void setInput(const std::string& data)
{
    static std::stringbuf sbuf;
    sbuf.str(data);
    std::cin.rdbuf(&sbuf);
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
    q.addQuestion("Столица России?", { "Москва", "СПб" }, 0);
    std::cout << "AddQuestion (визуально OK)\n";
}

void testStartCorrect()
{
    Quiz q;
    q.addQuestion("2+2=?", { "3", "4", "5" }, 1);
    setInput("2\n");
    q.start();
    assert(q.getScore() == 1);
    std::cout << "StartCorrect PASSED\n";
}

void testStartWrong()
{
    Quiz q;
    q.addQuestion("2+2=?", { "3", "4", "5" }, 1);
    setInput("1\n");
    q.start();
    assert(q.getScore() == 0);
    std::cout << "StartWrong PASSED\n";
}

void testReset()
{
    Quiz q;
    q.addQuestion("?", { "a" }, 0);
    q.start();
    q.reset();
    assert(q.getScore() == 0);
    std::cout << "Reset PASSED\n";
}

void testInputInt()
{
    setInput("abc\n789\n");
    int x = Quiz::inputInt("Введи число: ");
    assert(x == 789);
    std::cout << "InputInt PASSED\n";
}

void testInputString()
{
    setInput("   привет мир   \n");
    std::string s = Quiz::inputString("Введи строку: ");
    assert(s == "привет мир");
    std::cout << "InputString PASSED\n";
}

//int main() 
//{
//    testConstructor();
//    testAddQuestion();
//    testStartCorrect();
//    testStartWrong();
//    testReset();
//    testInputInt();
//    testInputString();
//    std::cout << "Все тесты прошли\n";
//    return 0;
//}