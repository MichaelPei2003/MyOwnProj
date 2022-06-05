#include <iostream>

using namespace std;

class B {
public:
    virtual void Show() const {
        cout << "B";
    }
};

class D : public B {
public:
    void Show() const {
        cout << "D";
    }
};

void Fun1(const B *p) {
    p->Show();
}

void Fun2(const B &obj) {
    obj.Show();
}

void Fun3(const B obj) {
    obj.Show();
}

int main() {
    B *p = new D;
    D d;
    Fun1(p);
    Fun2(d);
    Fun3(d);
    return 0;
}