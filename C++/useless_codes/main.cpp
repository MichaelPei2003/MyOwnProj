#include<bits/stdc++.h>

using namespace std;

class CPoint {
public:
    CPoint(double a, double b) : x(a), y(b) {}

    CPoint(CPoint &tmp) {
        x = tmp.x;
        y = tmp.y;
    }

    void GetPoint() {
        double a, b;
        cin >> a >> b;
        x = a;
        b = y;
    }

    double x;
    double y;
};

class CShape {
public:
    virtual bool HitIn(CPoint pos) = 0;

    virtual ~CShape() {}
};

class CUIControl {
public:
    bool HitTest(CPoint &pos) {
        return m_pShape->HitIn(pos);
    }

    void SetShape(CShape *pShape) {
        m_pShape = pShape;
    }

    virtual void clicked() = 0;

    virtual ~CUIControl() { delete m_pShape; }

private:
    CShape *m_pShape;
};

class CButton : public CUIControl {
public:
    CButton(string strName) : m_strName(strName) {}

    virtual void clicked() {
        cout << "button-" << m_strName << " Clicked" << endl;
    }

private:
    string m_strName;
};

class CMenu : public CUIControl {
public:
    CMenu(string strName) {
        m_strName = strName;
    }

    virtual void clicked() {
        cout << "menu-" << m_strName << " Clicked" << endl;
    }

private:
    string m_strName;
};

class CRectangle : public CShape {
public:
    CRectangle(CPoint pos, int x, int y) : m_pos(pos), m_iWidth(x), m_iHeight(y) {}

    virtual bool HitIn(CPoint pos) {
        double w, h;
        w = pos.x - m_pos.x;
        h = pos.y - m_pos.y;
        if ((w >= 0 && w <= m_iWidth) && (h >= 0 && h <= m_iHeight)) return true;
        return false;
    }

private:
    CPoint m_pos;
    int m_iWidth;
    int m_iHeight;
};

class CCircle : public CShape {
public:
    CCircle(CPoint center, double dRadius) : m_center(center), m_dRadius(dRadius) {}

    virtual bool HitIn(CPoint pos) {
        double a, b;
        a = m_center.x - pos.x;
        b = m_center.y - pos.y;
        double distance;
        distance = sqrt(a * a + b * b);
        if (distance <= m_dRadius) return true;
        return false;
    }

private:
    CPoint m_center;
    double m_dRadius;
};

int main() {
    CUIControl *p;
    CShape *q;
    vector<CUIControl *> jojo;
    int t;
    string s, tp;
    string menu("menu"), rectangle("rectangle"), circle("circle"), button("button");
    string menu_("menu_"), button_("button_");
    cin >> t;
    double a, b, r;
    int c, d;

    for (int i = 1; i <= t; i++) {
        cin >> s;
        if (s == menu) {
            cin >> s >> tp;
            p = new CMenu(s);
            if (tp == rectangle) {
                cin >> a >> b >> c >> d;
                CPoint pos(a, b);
                q = new CRectangle(pos, c, d);
                p->SetShape(q);
                jojo.push_back(p);
            } else if (tp == circle) {
                cin >> a >> b >> r;
                CPoint pos(a, b);
                q = new CCircle(pos, r);
                p->SetShape(q);
                jojo.push_back(p);
            }
        } else if (s == button) {
            cin >> s >> tp;
            p = new CButton(s);
            if (tp == rectangle) {
                cin >> a >> b >> c >> d;
                CPoint pos(a, b);
                q = new CRectangle(pos, c, d);
                p->SetShape(q);
                jojo.push_back(p);
            } else if (tp == circle) {
                cin >> a >> b >> r;
                CPoint pos(a, b);
                q = new CCircle(pos, r);
                p->SetShape(q);
                jojo.push_back(p);
            }
        }
    }

    int i;
    while (cin >> s) {
        cin >> a >> b;
        CPoint arrow(a, b);
        for (i = t - 1; i >= 0; i--) {
            if (jojo[i]->HitTest(arrow)) {
                jojo[i]->clicked();
                break;
            }
        }
        if (i == -1) cout << "none hit" << endl;
    }
}
