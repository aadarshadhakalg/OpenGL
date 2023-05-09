//
// Created by aadarshadhakalg on 5/9/23.
//

#include "DeadScreen.hpp"


int DeadScreen::display() {
    auto displayText = DisplayText::getInstance();
    float white[] = {1.0f,1.0f,1.0f,1.0f};
    displayText->render_text("REST IN PEACE!!",-0.2,-0.0, white,56,0,0);
    displayText->render_text("<< PRESS SPACE KEY TO RESTART >>",-0.19,-0.8,white,24,0,0);
    return 1;
}

std::string DeadScreen::getID() {
    return id;
}
