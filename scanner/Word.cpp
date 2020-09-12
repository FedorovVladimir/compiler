//
// Created by 3crabs on 12.09.2020.
//

#include "string"
#include "TypeWord.cpp"

using namespace std;

class Word {

private:
    TypeWord typeWord;
    string text;

public:
    explicit Word(TypeWord typeWord) : typeWord(typeWord) {}

    friend bool operator!=(const Word *w, TypeWord tw) {
        return w->typeWord != tw;
    }

    string str() {
        return toText(typeWord) + " " + text;
    }

    static string toText(TypeWord tw) {
        if (tw == ERROR) {
            return "ERROR";
        } else if (tw == END_OF_FILE) {
            return "END_OF_FILE";
        } else {
            return "TypeWord not found!";
        }
    }
};
