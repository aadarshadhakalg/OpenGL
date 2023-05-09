//
// Created by aadarshadhakalg on 5/9/23.
//

#ifndef HANGMAN_INPUTHANDLERS_HPP
#define HANGMAN_INPUTHANDLERS_HPP


#include "Navigator.hpp"
#include "StartScreen.hpp"
#include "GameScreen.hpp"

void goToHomeScreen(Navigator * navigator);


void goToGameScreen(Navigator * navigator);

void processInputKeys(GLFWwindow *window, int key, int scancode, int action, int mods);

#endif //HANGMAN_INPUTHANDLERS_HPP
