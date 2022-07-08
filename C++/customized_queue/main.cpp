#include <bits/stdc++.h>
#include <list>

using namespace std;

template<class T>
class CQueue {
    list<T> k;
public:
    CQueue() = default;

    ~CQueue() = default;

    CQueue(const CQueue &rhs) {
        k = rhs.k;
    }

    void operator=(CQueue &rhs) {
        k = rhs.k;
    }

    void Push(T p) {
        k.push_back(p);
    }

    void Pop() {
        auto i = k.begin();
        cout << *i << " ";
        k.pop_front();
    }

    void Display() {
        for (auto i = k.begin(); i != k.end(); i++) {
            cout << *i <<" ";
        }
    }
};

int main() {
    string s;
    cin >> s;
    cout << "Start:" << endl;
    if (s == "string") {
        CQueue<string> a[5];
        int n, m;
        int count;
        string p;
        cin >> count;
        //操作部分 
        while (count > 0) {
            cin >> s;
            if (s == "push") {
                cin >> n >> p;
                a[n].Push(p);
            } else if (s == "pop") {
                cin >> n;
                a[n].Pop();
            } else if (s == "assign") {
                cin >> n >> m;
                a[m] = a[n];
            }
            /*for(int i = 1; i < 5; i++){
                a[i].Display();
            }*/
            count--;
        }
        a[4] = a[1];
        cout << endl;
        cout << "Final:" << endl;
        for (int i = 1; i < 5; i++) {
            a[i].Display();
            if (i != 4) cout << endl;
        }
    } else {
        CQueue<int> a[5];
        int n, m;
        int count;
        cin >> count;
        //操作部分 
        while (count > 0) {
            cin >> s;
            if (s == "push") {
                cin >> n >> m;
                a[n].Push(m);
            } else if (s == "pop") {
                cin >> n;
                a[n].Pop();
            } else if (s == "assign") {
                cin >> n >> m;
                a[m] = a[n];
            }
            count--;
        }
        a[4] = a[1];
        cout << endl;
        cout << "Final:" << endl;
        for (int i = 1; i < 5; i++) {
            a[i].Display();
            if (i != 4) cout << endl;
        }
    }
}
