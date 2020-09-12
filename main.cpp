#include <iostream>
#include <fstream>

using namespace std;

string readCode(const string &path) {
    ifstream in(path);
    string text;
    getline(in, text, '\0');
    in.close();
    return text + "\n";
}

int main() {
    // чтаем файл
    string text = readCode("/home/vladimir/CLionProjects/compiler/resources/program.code");
    if (text == "\n") {
        cout << "File not found!" << endl;
        return 0;
    }

    cout << text << endl;
    return 0;
}
