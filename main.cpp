#include <iostream>
#include <fstream>
#include "scanner/Scanner.cpp"
#include "scanner/TypeWord.cpp"

const char *str(Word *w);

using namespace std;

string readCode(const string &path) {
    ifstream in(path);
    string text;
    getline(in, text, '\0');
    in.close();
    return text;
}

int main() {
    // чтаем файл
    string text = readCode("/home/vladimir/CLionProjects/compiler/resources/program.code");
    if (text.empty()) {
        cout << "File not found!" << endl;
        return 0;
    }

    auto *scanner = new Scanner(text);

    while (scanner->current() != END_OF_FILE) {
        cout << scanner->current()->str() << endl;
        scanner->next();
    }
    cout << scanner->current()->str() << endl;

    return 0;
}
