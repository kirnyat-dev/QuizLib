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
    while (true) {
        std::cout << "Ваш ответ (номер): ";
        std::string line;
        std::getline(std::cin, line);
        if (line.empty())
        {
            continue;
        }
        size_t start = line.find_first_not_of(" \t");
        if (start == std::string::npos)
        {
            std::cout << "Ошибка! Введите номер.\n";
            continue;
        }
        std::string numStr = line.substr(start);
        bool isNumber = true;
        for (char c : numStr)
        {
            if (!std::isdigit(static_cast<unsigned char>(c)))
            {
                isNumber = false;
                break;
            }
        }
        if (!isNumber)
        {
            std::cout << "Ошибка! Введите число.\n";
            continue;
        }
        int ans = std::stoi(numStr);
        if (ans >= 1 && ans <= optionsCount)
        {
            return ans - 1;
        }
        else
        {
            std::cout << "Ошибка: выберите номер от 1 до " << optionsCount << "\n";
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
            ++score;
        }
        else
        {
            std::cout << "Неверно. Правильный ответ: " << q.options[q.correctIndex] << "\n";
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
}

int Quiz::inputInt(const std::string& prompt)
{
    std::cout << prompt;
    while (true)
    {
        std::string line;
        std::getline(std::cin, line);
        if (line.empty())
        {
            continue;
        }
        size_t start = line.find_first_not_of(" \t");
        if (start == std::string::npos)
        {
            std::cout << "Ошибка! Введите число.\n";
            continue;
        }
        std::string numStr = line.substr(start);
        bool isNumber = true;
        for (char c : numStr)
        {
            if (!std::isdigit(static_cast<unsigned char>(c)))
            {
                isNumber = false;
                break;
            }
        }
        if (!isNumber)
        {
            std::cout << "Ошибка! Введите число.\n";
            continue;
        }
        return std::stoi(numStr);
    }
}

std::string Quiz::inputString(const std::string& prompt)
{
    std::cout << prompt;
    std::string s;
    std::getline(std::cin, s);
    size_t start = s.find_first_not_of(" \t");
    if (start == std::string::npos) return "";
    size_t end = s.find_last_not_of(" \t");
    return s.substr(start, end - start + 1);
}