#include "QuizLib.h"
#include <Windows.h>

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Quiz quiz;

    quiz.addQuestion("Сколько будет 2 + 2?", { "3", "4", "5" }, 1);

    std::vector<std::string> answers2 = { "Москва", "Париж", "Лондон" };
    quiz.addQuestion("Столица Франции?", answers2, 1);

    quiz.addQuestion("C++ - это ...", { "язык программирования", "компилятор", "среда разработки" }, 0);

    std::cout << "Добро пожаловать в викторину!\n";
    quiz.start();

    std::cout << "\nХотите попробовать ещё раз? (1 - да, 0 - нет): ";
    if (Quiz::inputInt("") == 1)
    {
        quiz.reset();      
        main();
    }
    return 0;
}