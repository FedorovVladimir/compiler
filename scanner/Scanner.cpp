//
// Created by 3crabs on 12.09.2020.
//

#include <utility>
#include "string"
#include "Word.cpp"
#include <iostream>

using namespace std;

const int countWords = 7;
const string words[] = {"void", "int", "double", "switch", "case", "break", "if"};
const TypeWord wordsTypes[] = {VOID, INT, DOUBLE, SWITCH, CASE, BREAK, IF};


const string ones = "(){};,+:-*";
const TypeWord onesTypes[] = {
        OPEN_KRUGLAY,
        CLOSE_KRUGLAY,
        OPEN_FIGURNAY,
        CLOSE_FIGURNAY,
        POINT_COMMA,
        COMMA,
        PLS,
        POINT_POINT,
        MNS,
        MUL
};

class Scanner {

private:
    string text;
    int cp; // current position
    int cl; // current line
    int cc; // current char

    int nextChar() {
        int r = cp;
        if (text[cp] == '\n') {
            cc = 1;
            cl++;
        } else {
            cc++;
        }
        cp++;
        return r;
    }

    void swapGarbageSymbols() {
        while (text[cp] == ' ' || text[cp] == '\n' || text[cp] == '\t' || text[cp] == '\r')
            nextChar();
    }

    bool swapComment() {
        if (text[cp] == '/' && text[cp + 1] == '/') {
            nextChar();
            nextChar();
            while (text[cp] != '\n') {
                nextChar();
            }
            return true;
        }
        return false;
    }

public:
    explicit Scanner(string text) {
        this->text = move(text) + "\n";
        this->cp = 0;
        this->cl = 1;
        this->cc = 1;
        cout << "Scanner get text!" << endl;
        cout << this->text << endl;
    }

    Word *next() {
        int i1 = cp;
        int i2 = cl;
        int i3 = cc;
        read();
        Word *p = read();
        cp = i1;
        cl = i2;
        cc = i3;
        return p;
    }

    Word *current() {
        int i1 = cp;
        int i2 = cl;
        int i3 = cc;
        Word *p = read();
        cp = i1;
        cl = i2;
        cc = i3;
        return p;
    }

    Word *read() {
        swapGarbageSymbols();
        while (swapComment()) {
            swapGarbageSymbols();
        }

        // end of file
        if (cp == text.length()) {
            return new Word(END_OF_FILE);
        }

        // words
        if (isalpha(text[cp])) {
            string s;
            s += text[nextChar()];
            while (isdigit(text[cp]) || isalpha(text[cp])) {
                s += text[nextChar()];
            }
            for (int i = 0; i < countWords; i++) {
                if (s == words[i]) {
                    return new Word(wordsTypes[i]);
                }
            }
            return new Word(ID, s);
        }

        // ();
        int indexOneSymbols = ones.find(text[cp]);
        if (0 <= indexOneSymbols && indexOneSymbols < ones.length()) {
            nextChar();
            return new Word(onesTypes[indexOneSymbols]);
        }

        // !=
        if (text[cp] == '!' && text[cp + 1] == '=') {
            nextChar();
            nextChar();
            return new Word(NOT_EQUAL);
        }
        // ==
        if (text[cp] == '=' && text[cp + 1] == '=') {
            nextChar();
            nextChar();
            return new Word(EQUAL_EQUAL);
        }

        // const_char
        if (text[cp] == '\'' && text[cp + 2] == '\'') {
            char ch = text[cp + 1];
            nextChar();
            nextChar();
            nextChar();
            // TODO char плохо выводится
            return new Word(CONST_CHAR, to_string(ch));
        }

        // const_string
        if (text[cp] == '"') {
            nextChar();
            string s;
            while (text[cp] != '"') {
                s += text[nextChar()];
            }
            nextChar();
            return new Word(CONST_STR, s);
        }

        // const_int const_double
        string s;
        if (isdigit(text[cp])) {
            s += text[cp];
            nextChar();
            while(isdigit(text[cp])) {
                s += text[cp];
                nextChar();
            }
            if (text[cp] == '.') {
                s += text[cp];
                nextChar();
                goto N1;
            } else if (text[currentPosition] == 'E' || text[currentPosition] == 'e') {
                s += text[currentPosition++];
                goto N2;
            }
            return new Node(CONST_INT, s);
        }
        if (text[currentPosition] == '.') {
            s += text[currentPosition++];
            if (isdigit(text[currentPosition])) {
                s += text[currentPosition++];
                goto N1;
            }
            return new Node(POINT, s);
        }
        N1:
        while (isdigit(text[currentPosition])) {
            s += text[currentPosition++];
        }
        if (text[currentPosition] == 'E' || text[currentPosition] == 'e') {
            s += text[currentPosition++];
            goto N2;
        }
        return new Node(CONST_DOUBLE, s);
        N2:
        if (text[currentPosition] == '+' || text[currentPosition] == '-') {
            s += text[currentPosition++];
            if (isdigit(text[currentPosition])) {
                s += text[currentPosition++];
                goto N3;
            } else {
                return new Node(ERROR);
            }
        }
        N3:
        while (isdigit(text[currentPosition])) {
            s += text[currentPosition++];
        }
        char* value = new char[s.length() + 1];
        strcpy(value, s.c_str());
        char * str = strtok(value, "Ee");
        double valueDouble = atof(str);
        str = strtok(nullptr, "Ee");
        valueDouble *= pow(10, atoi(str));
        return new Node(CONST_DOUBLE, to_string(valueDouble));

        return new Word(ERROR, "line: " + to_string(cl) + " number: " + to_string(cc) + " char: " + text[cp]);
    }
};
