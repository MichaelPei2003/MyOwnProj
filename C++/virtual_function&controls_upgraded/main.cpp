#include <bits/stdc++.h>

using namespace std;

class CPoint {
    int x;
    int y;
public:
    CPoint(int a, int b) : x{a}, y{b} {}

    ~CPoint() {}
};

class CShape {
public:
    CShape();

    virtual ~CShape() {}

    virtual bool HitIn() const = 0;
};

class CRectangle : public CShape {
    CPoint pos;
    int width;
    int height;
public:

};

class CCircle : public CShape {

};

class CUIControl {

public:
    CUIControl() {}

    virtual ~CUIControl() {}

    virtual void Click() = 0;
};

class CButton : public CUIControl {
    char *op;

public:
    CButton(char *ctrl) : op{ctrl} {}

    virtual ~CButton() {}
};

class CMenu : public CUIControl {
    char *op;
public:
    CMenu(char *ctrl) : op{ctrl} {}

    virtual ~CMenu();
};

int main() {
    int num, i, j;
    cin >> num;
    for (i = 0; i < num; i++) {

    }
}
