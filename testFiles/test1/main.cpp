#include <iostream>

using namespace std;

class CustomNum {
private:
    int numerator, denominator;
public:
    CustomNum() {};

    CustomNum(const CustomNum &tmp);

    CustomNum(int a, int b) : numerator(a), denominator(b) {};

    void Polish();

    void print();

    CustomNum operator+(CustomNum tmp);

    CustomNum operator-(CustomNum tmp);

    CustomNum operator*(CustomNum tmp);

    CustomNum operator/(CustomNum tmp);
};

CustomNum::CustomNum(const CustomNum &tmp) {
    numerator = tmp.numerator;
    denominator = tmp.denominator;
}

void CustomNum::print() {
    Polish();
    if (denominator < 0 && numerator > 0) {
        denominator = -denominator;
        numerator = -numerator;
    }
    cout << numerator;
    if (denominator != 1) {
        cout << "/" << denominator;
    }
}

void CustomNum::Polish() {
    //���ӷ�ĸ��Ϊ����ʱ ,תΪ����
    if (numerator < 0 && denominator < 0) {
        numerator = abs(numerator);
        numerator = abs(denominator);
    }
    if (denominator < 0 && numerator > 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
    //������Լ��
    int t;
    int num1 = abs(numerator);
    int num2 = abs(denominator);
    if (num1 > num2) t = num2;
    else t = num1;
    int i;
    for (i = t; i > 1; i--) {
        if (num1 % i == 0 && num2 % i == 0) break;
    }
    //����
    numerator = numerator / i;
    denominator = denominator / i;
}


CustomNum CustomNum::operator+(CustomNum tmp) {
    int a = numerator;
    int b = denominator;
    int c = tmp.numerator;
    int d = tmp.denominator;
    return CustomNum(a * d + b * c, b * d);
}

CustomNum CustomNum::operator-(CustomNum tmp) {
    tmp.numerator = -tmp.numerator;
    return operator+(tmp);
}

CustomNum CustomNum::operator*(CustomNum tmp) {
    int a = numerator;
    int b = denominator;
    int c = tmp.numerator;
    int d = tmp.denominator;
    return CustomNum(a * c, b * d);
}

CustomNum CustomNum::operator/(CustomNum tmp) {
    int a = numerator;
    int b = denominator;
    int c = tmp.numerator;
    int d = tmp.denominator;
    return CustomNum(a*d,b*c);
}

int main() {
    int a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;
    CustomNum num1(a1, a2), num2(b1, b2);
    num1.print();
    cout << endl;
    num2.print();
    cout << endl;

    CustomNum sum;
    sum = num1 + num2;
    sum.print();
    cout << "\t";

    CustomNum diff;
    diff = num1 - num2;
    diff.print();
    cout << "\t";

    CustomNum product;
    product = num1 * num2;
    product.print();
    cout << "\t";

//    cout<<endl;
//    num1.print();
//    cout<<endl;
//    num2.print();

    CustomNum quot;
    quot = num1 / num2;
    quot.print();
}
