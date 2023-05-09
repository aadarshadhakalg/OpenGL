//
// Created by aadarshadhakalg on 5/8/23.
//

#include <Navigator.hpp>


Screen* Navigator::getCurrentScreen() {
    return this->currentScreen;
}


int Navigator::setCurrentScreen(Screen* screen) {
    this->currentScreen = screen;
    return 1;
}

// Define the static Singleton pointer
Navigator* Navigator::inst_ = nullptr;

Navigator* Navigator::getInstance() {
    if (inst_ == nullptr) {
        inst_ = new Navigator();
    }
    return(inst_);
}
