#include<iostream>
#include<vector>
#include<string.h>
#include<math.h>

#define PI 3.14159
using namespace std;

class Shape {
public:
    virtual ~Shape() {}

    virtual double GetArea() const = 0;
};

class Circle : public Shape {
private:
    double r;
public:
    Circle(double a) : r(a) {}

    double GetArea() const { return PI * r * r; }
};

class Rectangle : public Shape {
private:
    double height;
    double width;
public:
    Rectangle(double h, double w) : height(h), width(w) {}

    double GetArea() const { return height * width; }
};

class Trangle : public Shape {
private:
    double e1, e2;
public:
    Trangle(double a, double b) : e1(a), e2(b) {}

    double GetArea() const {
        return e1 * e2 / 2;
    }
};

class T : public Shape {
private:
    double e1, e2, e3;
public:
    T(double a, double b, double c) : e1(a), e2(b), e3(c) {}

    double GetArea() const {
        return (e1 + e2) * e3 / 2;
    }
};

class Rect : public Shape {
private:
    double he;

public:
    Rect(double h) : he(h) {}

    double GetArea() const { return he * he; }
};

int main(void) {
    double a, b, c, d, e, f, g, h, i;
    cin >> a >> b >> c >> d >> e >> f >> g >> h >> i;
    double sum;
    Circle z1(a);
    Rect z2(b);
    Rectangle z3(c, d);
    T z4(e, f, g);
    Trangle z5(h, i);
    sum = z1.GetArea() + z2.GetArea() + z3.GetArea() + z4.GetArea() + z5.GetArea();
    printf("%.3lf", sum);
}
