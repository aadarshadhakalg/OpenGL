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


class GameScreen: public Screen {
private:
    Word* word;


public:

    GameScreen(){
        id = "gameScreen";
        word = DataService::getInstance()->getRandomMovieDetail();
    };
    ~GameScreen() = default;


    int display() override;
    void drawHangman(int failures);
    void drawCharPlaceHolder();
    std::string getID() override;
};


#endif //HANGMAN_GAMESCREEN_HPP
