#ifndef _QUIZLIB_H_
#define _QUIZLIB_H_

#include <string>
#include <vector>

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
        const std::vector<std::string>& options, int correctIndex);
    void start();
    int getScore() const;
    void reset();

    static int inputInt(const std::string& prompt);
    static std::string inputString(const std::string& prompt);
};

#endif //!_QUIZLIB_H_