#include <iostream>
#include <list>
//Written in CLion & UTF-8
using namespace std;

class Set {
    int num{};
public:
    list<int> set;

    void print();

    void storeSet(int n);
};

void Set::storeSet(int n) {
    int i;
    num = n;
    int tmp;
    for (i = 0; i < num; i++) {
        cin >> tmp;
        set.push_back(tmp);
    }
    set.sort();
    set.unique();
}

void Set::print() {
    int i;
    cout << "{";
    auto it = set.begin();
    for (i = 0; i < set.size(); i++, ++it) {
        cout << *it;
        if (i + 1 == set.size()) {
            cout << "}" << endl;
            break;
        }
        cout << ",";
    }
}

void print(list<int> set) {
    int i;
    cout << "{";
    auto it = set.begin();
    for (i = 0; i < set.size(); i++, ++it) {
        cout << *it;
        if (i + 1 == set.size()) {
            cout << "}" << endl;
            return;
        }
        cout << ",";
    }
    cout << "}" << endl;
}

void u(list<int> setA, list<int> setB) {
    list<int> tmp(setA.begin(), setA.end());
    tmp.merge(setA);
    tmp.merge(setB);
    tmp.sort();
    tmp.unique();
    print(tmp);
}

bool find(list<int> s, int n) {
    int i;
    auto it = s.begin();
    for (i = 0; i < s.size(); i++, ++it) {
        if (*it == n) {
            return true;
        }
    }
    return false;
}

void inter(list<int> setA, list<int> setB) {
    int i;
    list<int> tmp;
//    if (setA.size() >= setB.size()) {
    auto it = setA.begin();
    for (i = 0; i < setA.size(); i++, ++it) {
        if (find(setB, *it)) {
            tmp.push_front(*it);
        }
    }
//    } else {
//        auto it = setB.begin();
//        for (i = 0; i < setB.size(); i++, ++it) {
//            cout << i << endl;
//            system("pause");
//            if (find(setA, *it)) {
//                tmp.push_front(*it);
//                cout << tmp.size()<<endl;
//                system("pause");
//            }
//        }
//    }
    tmp.sort();
    print(tmp);
}

void differ(list<int> setA, list<int> setB){
    int i;
    list<int> tmp;
    auto it = setA.begin();
    for (i = 0; i < setA.size(); i++, ++it) {
        if (!find(setB, *it)) {
            tmp.push_front(*it);
        }
    }
    tmp.sort();
    print(tmp);
}

int main() {
    Set setA, setB;
    int a, b;
    cin >> a >> b;
    setA.storeSet(a);
    setB.storeSet(b);
    setA.print();
    setB.print();
    u(setA.set, setB.set);  //union
    inter(setA.set, setB.set);//intersection
    differ(setA.set, setB.set);//A-B
}
