//
// Created by 3crabs on 12.09.2020.
//

#include <utility>
#include "string"
#include "Word.cpp"
#include <iostream>

using namespace std;

class Scanner {

private:
    string text;
    int currentPosition;

    void swapGarbageSymbols() {
        while (text[currentPosition] == ' ' || text[currentPosition] == '\n' || text[currentPosition] == '\t' ||
               text[currentPosition] == '\r')
            currentPosition++;
    }

    void swapComment() {
        if (text[currentPosition] == '/' && text[currentPosition + 1] == '/') {
            currentPosition += 2;
            while (text[currentPosition] != '\r' && text[currentPosition] != '\0')
                currentPosition++;
            currentPosition++;
            while (text[currentPosition] == '\n') {
                currentPosition++;
            }
        }
    }

public:
    explicit Scanner(string text) {
        this->text = move(text) + "\n";
        this->currentPosition = 0;
        cout << "Scanner get text!" << endl;
        cout << this->text << endl;
    }

    void setCurrentPosition(const int position) {
        this->currentPosition = position;
    }

    int getCurrentPosition() {
        return currentPosition;
    }

    Word *next() {
        int i = getCurrentPosition();
        read();
        Word *p = next();
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
        return new Word(ERROR);
    }
};
