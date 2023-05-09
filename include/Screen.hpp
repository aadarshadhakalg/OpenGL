//
// Created by aadarshadhakalg on 5/9/23.
//

#ifndef HANGMAN_SCREEN_HPP
#define HANGMAN_SCREEN_HPP


#include <string>

class Screen{
protected:
    std::string id;

public:
    Screen() = default;
    virtual int display()  = 0;
    virtual std::string getID() = 0;
};

#endif //HANGMAN_SCREEN_HPP
