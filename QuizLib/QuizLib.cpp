#include "QuizLib.h"

Quiz::Quiz() : score(0) {}

void Quiz::addQuestion(const std::string& text, const std::vector<std::string>& options, int correctIndex)
{
    questions.push_back({ text, options, correctIndex });
}

void Quiz::showQuestion(const Question& q, int num)
{
    std::cout << "\nВопрос " << num << ": " << q.text << "\n";
    for (size_t i = 0; i < q.options.size(); ++i)
    {
        std::cout << "  " << (i + 1) << ". " << q.options[i] << "\n";
    }
}

int Quiz::askAnswer(int optionsCount)
{
    while (true)
    {
        int ans = inputInt("Ваш ответ (номер): ");
        if (ans >= 1 && ans <= optionsCount)
        {
            return ans - 1;
        }
        else
        {
            std::cout << "Ошибка: выбери номер от 1 до " << optionsCount << "\n";
        }
    }
}

void Quiz::start()
{
    score = 0;
    for (size_t i = 0; i < questions.size(); ++i)
    {
        const auto& q = questions[i];
        showQuestion(q, i + 1);
        int userChoice = askAnswer(q.options.size());
        if (userChoice == q.correctIndex)
        {
            std::cout << "Правильно! +1 балл\n";
            score++;
        }
        else
        {
            std::cout << "Неверно. Правильный ответ: "
                << q.options[q.correctIndex] << "\n";
        }
    }
    std::cout << "\nИтоговый счёт: " << score << " из " << questions.size() << "\n";
}

int Quiz::getScore() const
{
    return score;
}

void Quiz::reset()
{
    questions.clear();
    score = 0;
    system("cls");
}

int Quiz::inputInt(const std::string& prompt)
{
    std::cout << prompt;
    int val;
    while (!(std::cin >> val))
    {
        std::cout << "Ошибка! Введите число.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << prompt;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return val;
}

std::string Quiz::inputString(const std::string& prompt)
{
    std::cout << prompt;
    std::string s;
    std::getline(std::cin, s, '\n');
    size_t start = s.find_first_not_of(" \t\n\r");
    if (start == std::string::npos) return "";
    size_t end = s.find_last_not_of(" \t\n\r");
    return s.substr(start, end - start + 1);
}