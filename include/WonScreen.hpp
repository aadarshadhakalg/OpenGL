//
// Created by aadarshadhakalg on 5/9/23.
//

#ifndef HANGMAN_WONSCREEN_HPP
#define HANGMAN_WONSCREEN_HPP


#include "DisplayText.hpp"
#include "Screen.hpp"

class WonScreen : public Screen{

public:
    WonScreen(){
        id = "wonScreen";
    };
    ~WonScreen() = default;


    int display() override;
    std::string getID() override;
};


#endif //HANGMAN_WONSCREEN_HPP
