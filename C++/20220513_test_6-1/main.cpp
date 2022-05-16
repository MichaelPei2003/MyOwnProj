#include <iostream>

using namespace std;

#include <algorithm>

int cnt = 0;

template<class T>
class MyArray {
    T *data;
    int size;
public:
    MyArray(T s);

    ~MyArray();

    bool check();

    void sort();

    void display();
};

template<class T>
MyArray<T>::MyArray(T s) {
    size = s;
    data = new T[size];
    for (int i = 0; i < size; i++) {
        cin >> data[i];
    }
}

template<class T>
void MyArray<T>::sort() {
    std::sort(data, data + size);
}

template<class T>
void MyArray<T>::display() {
    if (cnt != 0) {
        cout << endl;
    }
    for (int i = 0; i < size; i++) {
        cout << data[i];
        if (i < size - 1)
            cout << " ";
    }
    cnt++;
}

//Untouchable area
template<class T>
MyArray<T>::~MyArray() { delete[] data; }

template<class T>
bool MyArray<T>::check() {
    int i;
    for (i = 0; i < size - 1; i++)
        if (data[i] > data[i + 1]) {
            cout << "ERROR!" << endl;
            return false;
        }
    return true;
}

int main() {
    MyArray<int> *pI;
    MyArray<float> *pF;
    MyArray<char> *pC;
    int ty, size;
    cin >> ty;
    while (ty > 0) {
        cin >> size;
        switch (ty) {
            case 1:
                pI = new MyArray<int>(size);
                pI->sort();
                pI->check();
                pI->display();
                delete pI;
                break;
            case 2:
                pF = new MyArray<float>(size);
                pF->sort();
                pF->check();
                pF->display();
                delete pF;
                break;
            case 3:
                pC = new MyArray<char>(size);
                pC->sort();
                pC->check();
                pC->display();
                delete pC;
                break;
        }
        cin >> ty;
    }
    return 0;
}