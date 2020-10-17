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

void testScannerFile(const string &filename) {
    // чтаем файл
    string text = readCode(filename);
    if (text.empty()) {
        cout << "File not found!" << endl;
    }

    // создаем сканер
    auto *scanner = new Scanner(text);

    while (scanner->current() != END_OF_FILE && scanner->current() != ERROR) {
        if (scanner->current() == ERROR) {
            cout << "ERROR in " << filename << endl;
        }
        scanner->read();
    }

    cout << "OK" << endl;
}

void testScannerAllFiles() {
    testScannerFile("/home/vladimir/CLionProjects/compiler/resources/hello_world.c");
    testScannerFile("/home/vladimir/CLionProjects/compiler/resources/switch_break.c");
    testScannerFile("/home/vladimir/CLionProjects/compiler/resources/var_assignment.c");
    testScannerFile("/home/vladimir/CLionProjects/compiler/resources/var_if_else.c");
    testScannerFile("/home/vladimir/CLionProjects/compiler/resources/var_if_while_func_bool.c");
    testScannerFile("/home/vladimir/CLionProjects/compiler/resources/var_massive_for_if.c");
}

int main() {
    testScannerAllFiles();
    return 0;
}
