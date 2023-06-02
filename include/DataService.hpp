//
// Created by aadarshadhakalg on 5/9/23.
//

#ifndef HANGMAN_DATASERVICE_HPP
#define HANGMAN_DATASERVICE_HPP
#include <string>
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
    Word* words[15] = {
            new Word("everton","Based in Mersyside"),
            new Word("liverpool","Based in Mersyside"),
            new Word("swansea","First Welsh team to reach the Premier Leauge"),
            new Word("chelsea","Owned by A russian Billionaire"),
            new Word("hull","Once managed by Phil Brown"),
            new Word("manchester-city","2013 FA Cup runners up"),
            new Word("newcastle-united","Gazza's first club"),
            new Word("alien","Science-Fiction horror film"),
            new Word("jaws","Giant great white shark"),
            new Word("gladiator","Historical drama"),
            new Word("manchester","Northern city in the UK"),
            new Word("milan","Home of AC and Inter"),
            new Word("madrid","Spanish capital"),
            new Word("amsterdam","Netherlands capital"),
            new Word("prague","Czech Republic capital"),
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
