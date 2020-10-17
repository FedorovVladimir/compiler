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

    friend bool operator==(const Word *w, TypeWord tw) {
        return w->typeWord == tw;
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
        } else if (tw == OPEN_KRUGLAY) {
            return "(";
        } else if (tw == CLOSE_KRUGLAY) {
            return ")";
        } else if (tw == OPEN_FIGURNAY) {
            return "{";
        } else if (tw == CLOSE_FIGURNAY) {
            return "}";
        } else if (tw == CONST_STR) {
            return "CONST_STR";
        } else if (tw == POINT_COMMA) {
            return ";";
        } else if (tw == INT) {
            return "int";
        } else if (tw == DOUBLE) {
            return "double";
        } else if (tw == COMMA) {
            return ",";
        } else if (tw == NOT_EQUAL) {
            return "!=";
        } else if (tw == PLS) {
            return "+";
        } else if (tw == SWITCH) {
            return "switch";
        } else if (tw == CASE) {
            return "case";
        } else if (tw == CONST_CHAR) {
            return "CONST_CHAR";
        } else if (tw == POINT_POINT) {
            return ":";
        } else if (tw == BREAK) {
            return "break";
        } else if (tw == MNS) {
            return "-";
        } else if (tw == EQUAL_EQUAL) {
            return "==";
        } else if (tw == MUL) {
            return "*";
        } else if (tw == DIV) {
            return "/";
        } else if (tw == MOD) {
            return "%";
        } else if (tw == IF) {
            return "if";
        } else if (tw == CONST_DEC) {
            return "CONST_DEC";
        } else if (tw == BOOL) {
            return "BOOL";
        } else if (tw == EQUAL) {
            return "=";
        } else if (tw == LESS) {
            return "<";
        } else if (tw == INC) {
            return "++";
        } else if (tw == TRUE) {
            return "true";
        } else if (tw == FALSE) {
            return "false";
        } else if (tw == ELSE) {
            return "else";
        } else if (tw == CHAR) {
            return "char";
        } else if (tw == SHORT) {
            return "short";
        } else if (tw == LONG) {
            return "long";
        } else if (tw == DEC) {
            return "--";
        } else if (tw == RETURN) {
            return "return";
        } else if (tw == DEFAULT) {
            return "default";
        } else {
            return "TypeWord not found!";
        }
    }
};
