#include <bits/stdc++.h>

using namespace std;

class CUIControl {

public:
    CUIControl() {}

    virtual ~CUIControl() {};

    virtual void Click() = 0;
};

class CMenu : virtual public CUIControl {
    char *op;
public:
    CMenu(char *a) {
        op = new char[strlen(a) + 1];
        strcpy(op, a);
    }

    ~CMenu() {
        delete[]op;
    }

    void Click() {
        cout << "menu-" << op << " Clicked";
    }
};

class CButton : virtual public CUIControl {
    char *op;
public:
    CButton(char *a) {
        op = new char[strlen(a) + 1];
        strcpy(op, a);
    }

    ~CButton() {
        delete[]op;
    }

    void Click() {
        cout << "button-" << op << " Clicked";
    }
};

int main() {
    CUIControl *p;
    vector<CUIControl *> vec;
    int tmp;
    cin >> tmp;
    if (tmp < 0) {
        cout << "Invalid input.";
        main();
        exit(0);
    }
    char s[20];
    char op[20];
    while (tmp > 0) {
        cin >> s;
        if (!strcmp(s, "menu")) {
            cin >> op;
            p = new CMenu(op);
            vec.push_back(p);
        } else if (!strcmp(s, "button")) {
            cin >> op;
            p = new CButton(op);
            vec.push_back(p);
        }
        tmp--;
    }
    int sel;
    while (cin >> s) {
        cout << endl;
        cin >> sel;
        vec[sel - 1]->Click();
    }
}