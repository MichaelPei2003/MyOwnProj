#include<iostream>

using namespace std;

class Student {
    int score;
public:
    explicit Student(int s);

    static int Sum;
};

Student::Student(int s) : score(s) {
    Sum += score;
}

int Student::Sum = 0;

int main() {
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    Student stu0(a), stu1(b), stu2(c), stu3(d), stu4(e);
    cout << Student::Sum << endl << Student::Sum / 5;
}
