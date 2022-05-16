#include <iostream>

using namespace std;

template<class T>
class Calculation {
    T a;
    T b;
public:
    void read();

    void display();
};

template<class T>
void Calculation<T>::read() {
    cin >> a >> b;
}

template<class T>
void Calculation<T>::display() {
    cout << max(a, b) << " " << min(a, b) << " " << a + b << " " << a - b << " " << a * b << " " << a / b;
}

int main() {
    Calculation<int> a;
    Calculation<float> b;
    a.read();
    a.display();
    cout << endl;
    b.read();
    b.display();
}
