//
// Created by 3crabs on 12.09.2020.
//

#include <utility>
#include "string"
#include "Word.cpp"
#include <iostream>

using namespace std;

const int countWords = 1;
const string words[] = {"void"};
const TypeWord types[] = {VOID};

class Scanner {

private:
    string text;
    int cp; // current position

    void swapGarbageSymbols() {
        while (text[cp] == ' ' || text[cp] == '\n' || text[cp] == '\t' ||
               text[cp] == '\r')
            cp++;
    }

    void swapComment() {
        if (text[cp] == '/' && text[cp + 1] == '/') {
            cp += 2;
            while (text[cp] != '\r' && text[cp] != '\0')
                cp++;
            cp++;
            while (text[cp] == '\n') {
                cp++;
            }
        }
    }

public:
    explicit Scanner(string text) {
        this->text = move(text) + "\n";
        this->cp = 0;
        cout << "Scanner get text!" << endl;
        cout << this->text << endl;
    }

    void setCurrentPosition(const int position) {
        this->cp = position;
    }

    int getCurrentPosition() {
        return cp;
    }

    Word *next() {
        int i = getCurrentPosition();
        read();
        Word *p = read();
        setCurrentPosition(i);
        return p;
    }

    Word *current() {
        int i = getCurrentPosition();
        Word *p = read();
        setCurrentPosition(i);
        return p;
    }

    Word *read() {
        swapGarbageSymbols();
        swapComment();

        if (cp == text.length()) {
            return new Word(END_OF_FILE);
        }

        if (isalpha(text[cp])) {
            string s;
            s += text[cp++];
            while (isdigit(text[cp]) || isalpha(text[cp])) {
                s += text[cp++];
            }
            for (int i = 0; i < countWords; i++) {
                if (s == words[i]) {
                    return new Word(types[i]);
                }
            }
            return new Word(ID, s);
        }

        return new Word(ERROR);
    }
};
