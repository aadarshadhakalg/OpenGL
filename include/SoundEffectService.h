//
// Created by aadarshadhakalg on 6/2/23.
//

#ifndef HANGMAN_SOUNDEFFECTSERVICE_H
#define HANGMAN_SOUNDEFFECTSERVICE_H

#include <irrKlang.h>

using namespace irrklang;

class SoundEffectService{

private:
    ISoundEngine* engine ;

    static SoundEffectService* inst_;   // The one, single instance
    SoundEffectService(const SoundEffectService&);
    SoundEffectService& operator=(const SoundEffectService&);

    SoundEffectService(){
        engine = createIrrKlangDevice();
    }

public:
    static SoundEffectService* getInstance();
    void playStartSound();
    void playKeySound();
    void playBackgroundSound();
    void playCongratulationSound();
    void playRIPSound();
    void stopSound();
};

#endif //HANGMAN_SOUNDEFFECTSERVICE_H
