#include <iostream>
#include <fstream>
#include "scanner/Scanner.cpp"
#include "scanner/TypeWord.cpp"

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
    string text = readCode("/home/vladimir/CLionProjects/compiler/resources/program.c");
    if (text.empty()) {
        cout << "File not found!" << endl;
        return 0;
    }

    // создаем сканер
    auto *scanner = new Scanner(text);

    while (scanner->current() != END_OF_FILE && scanner->current() != ERROR) {
        cout << scanner->current()->str() << endl;
        scanner->read();
    }
    cout << scanner->current()->str() << endl;

    return 0;
}
