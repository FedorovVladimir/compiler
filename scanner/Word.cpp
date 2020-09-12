//
// Created by 3crabs on 12.09.2020.
//

#include <utility>

#include "string"
#include "TypeWord.cpp"

using namespace std;

class Word {

private:
    TypeWord typeWord;
    string text;

public:
    explicit Word(TypeWord typeWord) : typeWord(typeWord) {}

    Word(TypeWord typeWord, string text) : typeWord(typeWord), text(move(text)) {}

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
        } else if (tw == VOID) {
            return "VOID";
        } else if (tw == ID) {
            return "ID";
        } else {
            return "TypeWord not found!";
        }
    }
};
