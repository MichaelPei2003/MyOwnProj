#include<iostream>

using namespace std;

class Complex {
    double real;
    double image;
public:
    Complex(double r = 0, double i = 0) : real{r}, image{i} {}

    friend Complex Add(Complex &rhs1, Complex &rhs2);

    Complex Trans();

    void print();
};

Complex Add(Complex &rhs1, Complex &rhs2) {
    Complex z(rhs1.real + rhs2.real, rhs1.image + rhs2.image);
    return z;
}

void Complex::print() {
    cout << "(" << real << ", " << image << ")";
}

Complex Complex::Trans() {
    Complex z(-real, -image);
    return z;
}

int main() {
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    Complex c1(a, b);
    Complex c2(c, d);
    Complex c3 = Add(c1, c2);
    Complex c4 = c2.Trans();
    Complex c5 = Add(c1, c4);
    c3.print();
    cout << endl;
    c5.print();
    cout << endl;
    c2.print();
    return 0;
}
