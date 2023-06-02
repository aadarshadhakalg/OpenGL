//
// Created by aadarshadhakalg on 5/9/23.
//

#ifndef HANGMAN_GAMESCREEN_HPP
#define HANGMAN_GAMESCREEN_HPP


#include "Screen.hpp"
#include <DisplayText.hpp>
#include <DataService.hpp>
#include <Utilities.hpp>
#include "DrawHangman.hpp"
#include "InputHandlers.hpp"


class GameScreen: public Screen {
private:
    Word* word;
    int failedAttempt =0;

public:

    GameScreen(){
        id = "gameScreen";
        word = DataService::getInstance()->getRandomMovieDetail();

        SoundEffectService::getInstance()->playBackgroundSound();
    };
    ~GameScreen() = default;


    int display() override;
    void drawHangman();
    void drawCharPlaceHolder();
    std::string getID() override;
};


#endif //HANGMAN_GAMESCREEN_HPP
