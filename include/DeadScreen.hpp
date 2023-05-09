//
// Created by aadarshadhakalg on 5/9/23.
//

#ifndef HANGMAN_DEADSCREEN_HPP
#define HANGMAN_DEADSCREEN_HPP


#include "Screen.hpp"
#include "DisplayText.hpp"

class DeadScreen: public Screen{

public:
    DeadScreen(){
        id = "deadScreen";
    };
    ~DeadScreen() = default;


    int display() override;
    std::string getID() override;
};


#endif //HANGMAN_DEADSCREEN_HPP
