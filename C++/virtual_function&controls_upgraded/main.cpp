#include <bits/stdc++.h>

using namespace std;

int isFirstLine = 1;
int hit = -1;

class CPoint {
public:
    int x;
    int y;

    CPoint(int a, int b) : x{a}, y{b} {}

    ~CPoint() = default;

    CPoint(const CPoint &p) {
        x = p.x;
        y = p.y;
    }
};

class CShape {
public:
    CShape() = default;

    virtual ~CShape() = default;

    virtual bool HitIn(int x, int y) const = 0;
};

class CRectangle : public CShape {
    CPoint pos;
    int width;
    int height;
public:
    CRectangle(int w, int h, CPoint p) : width(w), height(h), pos(p) {}

    ~CRectangle() override {}

    bool HitIn(int x, int y) const {
        if (x >= pos.x && x <= pos.x + width && y >= pos.y && y <= pos.y + height) {
            return true;
        } else {
            return false;
        }
    }
};

class CCircle : public CShape {
    CPoint pos;
    double radius;
public:
    CCircle(double r, CPoint p) : radius(r), pos(p) {}

    ~CCircle() {}

    bool HitIn(int x, int y) const {
        double d = sqrt(pow((x - pos.x), 2) + pow((y - pos.y), 2));
        if (d <= radius) {
            return true;
        } else {
            return false;
        }
    }
};

class CUIControl {
public:
    CShape *pShape;
    string op;

    CUIControl(string ctrl) : op(ctrl) {}

    void SetShape(CShape *p) {
        pShape = p;
    }

    virtual ~CUIControl() {
        delete pShape;
    }

    virtual bool Click(int x, int y) = 0;
};

class CButton : public CUIControl {

public:
    CButton(string ctrl) : CUIControl(ctrl) {}

    ~CButton() {}

    bool Click(int x, int y) {
        if (pShape->HitIn(x, y)) {
            if(isFirstLine == 0) {
                cout<<endl;
            }
            isFirstLine = 0;
            cout << "button-" << op << " Clicked";
            hit++;
            return true;
        }
        return false;
    }
};

class CMenu : public CUIControl {
public:
    CMenu(string ctrl) : CUIControl(ctrl) {}

    ~CMenu() {}

    bool Click(int x, int y) {
        if (pShape->HitIn(x, y)) {
            if(isFirstLine == 0) {
                cout<<endl;
            }
            isFirstLine = 0;
            cout << "menu-" << op << " Clicked";
            hit++;
            return true;
        }
        return false;
    }
};

int main() {
    CShape *pShape;
    CUIControl *pCtrl;
    vector<CUIControl *> vec;
    int num;
    cin >> num;
    if (num < 0) {
        cout << "Invalid input.";
        return 0;
    }
    string shape, ctrl, op;
    string menu("menu"), button("button"), rectangle("rectangle"), circle("circle");
    for (int i = 0; i < num; i++) {
        cin >> ctrl;
        if (ctrl == menu) {
            cin >> op >> shape;
            pCtrl = new CMenu(op);
            if (shape == rectangle) {
                int x, y, w, h;
                cin >> x >> y >> w >> h;
                CPoint pos(x, y);
                pShape = new CRectangle(w, h, pos);
                pCtrl->SetShape(pShape);
                vec.push_back(pCtrl);
            } else if (shape == circle) {
                int x, y;
                double r;
                cin >> x >> y >> r;
                CPoint pos(x, y);
                pShape = new CCircle(r, pos);
                pCtrl->SetShape(pShape);
                vec.push_back(pCtrl);
            }
        }
        if (ctrl == button) {
            cin >> op >> shape;
            pCtrl = new CButton(op);
            if (shape == rectangle) {
                int x, y, w, h;
                cin >> x >> y >> w >> h;
                CPoint pos(x, y);
                pShape = new CRectangle(w, h, pos);
                pCtrl->SetShape(pShape);
                vec.push_back(pCtrl);
            } else if (shape == circle) {
                int x, y;
                double r;
                cin >> x >> y >> r;
                CPoint pos(x, y);
                pShape = new CCircle(r, pos);
                pCtrl->SetShape(pShape);
                vec.push_back(pCtrl);
            }
        }
    }
    int x, y;
    while (cin >> ctrl) {
        hit = -1;
        cin >> x >> y;
        for (int i = num - 1; i >= 0; i--) {
            if(vec[i]->Click(x, y)){
                break;
            }
        }
        if (hit == -1) {
            cout << endl << "none hit";
        }
    }
}

