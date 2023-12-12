#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class Line;

class Point;

class Line {
    double m_a;
    double m_b;
    double m_c;
public:
    friend double dist(Point p, Line l);

    void storeL(double a, double b, double c);
};

class Point {
    double m_x;
    double m_y;
public:
    friend double dist(Point p, Line l);

    void storeP(double x, double y);
};

void Line::storeL(double a, double b, double c) {
    m_a = a;
    m_b = b;
    m_c = c;
}

void Point::storeP(double x, double y) {
    m_x = x;
    m_y = y;
}

double dist(Point p, Line l) {
    double dis;
    dis = abs((l.m_a * p.m_x + l.m_b * p.m_y + l.m_c) / sqrt(l.m_a * l.m_a + l.m_b * l.m_b));
    return dis;
}

int main() {
    double a, b, c, x, y, d;
    Point p1;
    Line l1;
    cin >> x >> y;
    cin >> a >> b >> c;
    p1.storeP(x, y);
    l1.storeL(a, b, c);
    d = dist(p1, l1);
    cout.setf(ios::fixed);
    cout << "The distance is: " << setprecision(2) << d;
    return 0;
}