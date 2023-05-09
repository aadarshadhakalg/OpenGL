//
// Created by aadarshadhakalg on 5/9/23.
//

#ifndef HANGMAN_DATASERVICE_HPP
#define HANGMAN_DATASERVICE_HPP
#include <string>
#include <restc-cpp/restc-cpp.h>
#include <vector>

class Word{
private:
    std::string name;
    std::string hint;

public:
    Word(std::string name, std::string hint){
        this->name = name;
        this->hint = hint;
    }

    std::string getWord(){
        return this->name;
    }

    std::string getWordHint(){
        return this->hint;
    }
};

class DataService {
private:
    Word* words[10] = {
            new Word("dilbar","A Famous Indian Song featuring Nora Fatehi 1"),
            new Word("dilbar","A Famous Indian Song featuring Nora Fatehi 2"),
            new Word("dilbar","A Famous Indian Song featuring Nora Fatehi 3"),
            new Word("dilbar","A Famous Indian Song featuring Nora Fatehi 4"),
            new Word("dilbar","A Famous Indian Song featuring Nora Fatehi 5"),
            new Word("dilbar","A Famous Indian Song featuring Nora Fatehi 6"),
            new Word("dilbar","A Famous Indian Song featuring Nora Fatehi 7"),
            new Word("dilbar","A Famous Indian Song featuring Nora Fatehi 8"),
            new Word("dilbar","A Famous Indian Song featuring Nora Fatehi 9"),
            new Word("dilbar","A Famous Indian Song featuring Nora Fatehi 10"),

    };
    static DataService* inst_;   // The one, single instance
    DataService()=default;
    DataService(const DataService&);
    DataService& operator=(const DataService&);

public:
    std::vector<char> typpedWords;
    int failures = 0;
    static DataService*   getInstance();
    Word* getRandomMovieDetail();
};

#endif //HANGMAN_DATASERVICE_HPP
