//
// Created by aadarshadhakalg on 5/9/23.
//

#include "GameScreen.hpp"

int GameScreen::display() {
    DataService* dataService = DataService::getInstance();
    auto typpedWords = dataService->typpedWords;
    auto displayText = DisplayText::getInstance();
    float white[] = {1.0f,1.0f,1.0f,1.0f};
    displayText->render_text(("Hint: " + word->getWordHint()).c_str(),-0.5,0.8, white,36,0,0);


    drawHangman(0);

    // Bottom Separator
    glBegin(GL_LINES);
    glVertex2f(-1.0, -0.75);
    glVertex2f(1.0, -0.75);
    glEnd();

    //Trash Char Display

    displayText->render_text(("Trash: " + convertToString(typpedWords)).c_str(),-0.9,-0.9,white,36,0,0);
    return 1;
}

std::string GameScreen::getID() {
    return id;
}

void GameScreen::drawHangman(int failures) {
    if(failures)
}
