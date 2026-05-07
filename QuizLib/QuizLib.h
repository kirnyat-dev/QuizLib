#ifndef QUIZLIB_H
#define QUIZLIB_H

#include <string>
#include <vector>
#include <iostream>
#include <limits>
#include <cctype>

class Quiz {
private:
    struct Question {
        std::string text;
        std::vector<std::string> options;
        int correctIndex;
    };
    std::vector<Question> questions;
    int score;

    void showQuestion(const Question& q, int num);
    int askAnswer(int optionsCount);

public:
    Quiz();
    void addQuestion(const std::string& text,
        const std::vector<std::string>& options,
        int correctIndex);
    void start();
    int getScore() const;
    void reset();

    static int inputInt(const std::string& prompt);
    static std::string inputString(const std::string& prompt);
};

#endif //!_QUIZLIB_H_