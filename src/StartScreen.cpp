#include <StartScreen.hpp>


int StartScreen::display() {
    auto displayText = DisplayText::getInstance();
    float white[] = {1.0f,1.0f,1.0f,1.0f};
    displayText->render_text("HANGMAN",-0.2,-0.0, white,96,0,0);
    displayText->render_text("<< PRESS SPACE KEY TO START >>",-0.19,-0.8,white,24,0,0);
    return 1;
}

std::string StartScreen::getID() {
    return id;
}


