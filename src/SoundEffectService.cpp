#include "SoundEffectService.h"

//
// Created by aadarshadhakalg on 6/2/23.
//
SoundEffectService* SoundEffectService::inst_ = nullptr;

SoundEffectService* SoundEffectService::getInstance() {
    if (inst_ == nullptr) {
        inst_ = new SoundEffectService();
    }
    return(inst_);
}

void SoundEffectService::playStartSound() {
    stopSound();
    engine->play2D("../sounds/start.mp3");

}

void SoundEffectService::playKeySound() {
    engine->play2D("../sounds/solid.wav");
}

void SoundEffectService::playCongratulationSound() {
    stopSound();
    engine->play2D("../sounds/win.mp3");
}

void SoundEffectService::playRIPSound() {
    stopSound();
    engine->play2D("../sounds/rip.mp3");
}

void SoundEffectService::stopSound() {
    engine->stopAllSounds();
}

void SoundEffectService::playBackgroundSound() {
    stopSound();
    engine->play2D("../sounds/breakout.mp3");
}

