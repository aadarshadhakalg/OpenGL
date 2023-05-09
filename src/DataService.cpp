//
// Created by aadarshadhakalg on 5/9/23.
//

#include "DataService.hpp"

Word* DataService::getRandomMovieDetail() {
    int randomIndex = rand() % 10;
    return words[randomIndex];
}
// Define the static Singleton pointer
DataService* DataService::inst_ = nullptr;

DataService* DataService::getInstance() {
    if (inst_ == nullptr) {
        inst_ = new DataService();
    }
    return(inst_);
}