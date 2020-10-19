//
// Created by vladimir on 19.10.2020.
//

#include "vector"
#include "string"
#include "iostream"

using namespace std;

class GScanner {

private:
    vector<string> v;

public:

    vector<string> push(const string &s) {
        v.push_back(s);
        return v;
    }

    void display() {
        for (const auto &i : v) {
            cout << i << ' ';
        }
        cout << endl;
    }

    bool empty() {
        return v.empty();
    }

    string pop() {
        string a = v[v.size() - 1];
        v.pop_back();
        return a;
    }
};
