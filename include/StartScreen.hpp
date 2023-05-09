#ifndef FLAG_START_SCREEN_HPP
#define FLAG_START_SCREEN_HPP

#include <DisplayText.hpp>
#include <GLFW/glfw3.h>
#include <string>
#include <Navigator.hpp>
#include <Screen.hpp>


class StartScreen : public Screen{

public:
    StartScreen(){
        id = "startScreen";
    };
    ~StartScreen() = default;


    int display() override;
    std::string getID() override;
};

#endif