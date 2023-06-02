//
// Created by aadarshadhakalg on 5/9/23.
//

#include <csignal>
#include "GameScreen.hpp"

int GameScreen::display() {
    DataService* dataService = DataService::getInstance();
    auto typpedWords = dataService->typpedWords;
    auto displayText = DisplayText::getInstance();
    float white[] = {1.0f,1.0f,1.0f,1.0f};
    displayText->render_text(("Hint: " + word->getWordHint()).c_str(),-0.5,0.8, white,36,0,0);


    drawHangman();
    drawCharPlaceHolder();

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

void GameScreen::drawHangman() {
    if(failedAttempt >= 0){
        drawBar();
    }

    if(failedAttempt >=1){
        drawHead();
    }
    if(failedAttempt >=2){
        drawBody();
    }
    if(failedAttempt >=3){
        drawRightHand();
    }
    if(failedAttempt >= 4){
        drawLeftHand();
    }
    if(failedAttempt >= 5){
        drawLeftLeg();
    }
    if(failedAttempt >= 6){
        drawRightLeg();
    }
    if(failedAttempt >= 7){
        drawRope();
        sleep(1);
        Navigator* navigator = Navigator::getInstance();
        goToDeadScreen(navigator);
    }
}

void GameScreen::drawCharPlaceHolder() {
    // x start from -0.3
    // max 10 chars
    bool isComplete = true;
    std::vector<char> detectedChar;
    DataService* dataService = DataService::getInstance();
    std::vector<char> typedWords = dataService->typpedWords;

    //Answer Word
    std::string answerWord = word->getWord();
    float white[] = {1.0f,1.0f,1.0f,1.0f};

    float startAtX = -0.3;
    for (int i = 0; i < strlen(word->getWord().c_str()); ++i) {

        if (std::count(typedWords.begin(), typedWords.end(), answerWord[i])) {
            char letter = answerWord[i];
            DisplayText::getInstance()->render_text(&letter,startAtX+0.01,0.0,white,48,0,0);

            if (!std::count( detectedChar.begin(), detectedChar.end(), letter)) {
                detectedChar.push_back(letter);
            }

        }else{
            isComplete = false;
        }
        glBegin(GL_LINES);
        glVertex2f(startAtX, 0.0);
        glVertex2f(startAtX + 0.05, 0.0);
        glEnd();
        startAtX = startAtX + 0.1;
    }

    if(isComplete){
        Navigator* navigator = Navigator::getInstance();
        goToWonScreen(navigator);
    }

    failedAttempt = typedWords.size() - detectedChar.size();
}
