//
// Created by aadarshadhakalg on 5/9/23.
//

#ifndef HANGMAN_DEADSCREEN_HPP
#define HANGMAN_DEADSCREEN_HPP


#include "Screen.hpp"
#include "DisplayText.hpp"
#include "SoundEffectService.h"

class DeadScreen: public Screen{

public:
    DeadScreen(){
        id = "deadScreen";
        SoundEffectService::getInstance()->playRIPSound();
    };
    ~DeadScreen() = default;


    int display() override;
    std::string getID() override;
};


#endif //HANGMAN_DEADSCREEN_HPP
