//
// Created by aadarshadhakalg on 5/8/23.
//

#ifndef FLAG_NAVIGATOR_HPP
#define FLAG_NAVIGATOR_HPP

#include <functional>
#include <Screen.hpp>
#include <string>
#include <map>


class Navigator {

private:
    Screen* currentScreen;
    static Navigator* inst_;   // The one, single instance
    Navigator()=default;
    Navigator(const Navigator&);
    Navigator& operator=(const Navigator&);

public:
    static Navigator* getInstance();
    Screen* getCurrentScreen();
    int setCurrentScreen(Screen* screen);

};


#endif //FLAG_NAVIGATOR_HPP
