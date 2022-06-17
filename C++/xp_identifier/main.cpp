#include <iostream>
#include <string>

using namespace std;

class Storage {
    string name;
    string xp;
public:
    Storage() = default;

    Storage(string name, string s) : name{move(name)}, xp{s} {}

    Storage(const Storage &x) {
        name = x.name;
        xp = x.xp;
    }

    Storage &operator=(Storage x) {
        this->xp = x.xp;
    }

    friend void ShowStorage(Storage &rhs);
};

void ShowStorage(Storage &rhs) {
    cout << rhs.name << "'s xp :" << rhs.xp;
}

int main() {
    string s;
    cout << "Input xp :";
    getline(cin, s);
    Storage pxy("pxy", s);
    ShowStorage(pxy);
    return 0;
}


