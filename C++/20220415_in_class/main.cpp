#include <iostream>

#define PI 3.14159

using namespace std;

class Shape {

public:
    Shape() {}

    virtual ~Shape() {}

    virtual float calculate() {}
};

class Circle : virtual public Shape {
    float r;
public:
    Circle(float x){
        r = x;
    }
    virtual float calculate() {
        float s;
        s = r * r * PI;
        return s;
    }
};

class Square : virtual public Shape {
float sqr;
public:
    Square(float x){
        sqr = x;
    }
    virtual float calculate() {
        float s;
        s = sqr * sqr;
        return s;
    }
};

class Rectangle : virtual public Shape {
    float recA;
    float recB;
public:
    Rectangle(float x, float y){
        recA = x;
        recB = y;
    }
    virtual float calculate() {
        float s;
        s = recA * recB;
        return s;
    }

};

class Trapezoid : virtual public Shape {
    float traT;
    float traB;
    float traH;
public:
    Trapezoid(float x, float y, float z){
        traT = x;
        traB = y;
        traH = z;
    }
    virtual float calculate() {
        float s;
        s = (traT + traB) * traH * 0.5;
        return s;
    }
};

class Triangle : virtual public Shape {
    float triB;
    float triH;
public:
    Triangle(float x, float y){
        triB = x;
        triH = y;
    }
    virtual float calculate() {
        float s;
        s = triB * triH * 0.5;
        return s;
    }
};

int main() {
    float r;
    float sqr;
    float recA;
    float recB;
    float traT;
    float traB;
    float traH;
    float triB;
    float triH;
    cin >> r >> sqr >> recA >> recB >> traT >> traB >> traH >> triB >> triH;
    Circle circle(r);
    Square square(sqr);
    Rectangle rectangle(recA, recB);
    Trapezoid trapezoid(traT, traB, traH);
    Triangle triangle(triB, triH);

}
