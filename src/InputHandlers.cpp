//
// Created by aadarshadhakalg on 5/9/23.
//

#include <InputHandlers.hpp>

void goToHomeScreen(Navigator * navigator){
    Screen* startScreen = new StartScreen();
    navigator->setCurrentScreen(startScreen);
}


void goToGameScreen(Navigator * navigator){
    DataService::getInstance()->typpedWords.clear();
    Screen* gameScreen = new GameScreen();
    navigator->setCurrentScreen(gameScreen);
}

void processInputKeys(GLFWwindow *window, int key, int scancode, int action, int mods) {
    auto* gameNavigator = Navigator::getInstance();

    if(action == GLFW_PRESS) return;

    if (key == GLFW_KEY_SPACE && action == GLFW_RELEASE )
    {
        std::cout << "Start The Game" << std::endl;
        goToGameScreen(gameNavigator);

    }else if (key == GLFW_KEY_ESCAPE && action == GLFW_RELEASE)
    {
        if(gameNavigator->getCurrentScreen()->getID() == "gameScreen"){
            goToHomeScreen(gameNavigator);
        }else{
            exit(0);
        }
    }else{
        const char* key_name = glfwGetKeyName(key, 0);
        if(key_name != NULL){
            DataService* dataService = DataService::getInstance();
            std::vector<char> currentList = dataService->typpedWords;
            if (!std::count( currentList.begin(), currentList.end(), *key_name)) {
                dataService->typpedWords.push_back(*key_name);
            }
        }

    }

}