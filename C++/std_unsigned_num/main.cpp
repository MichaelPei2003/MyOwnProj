#include <bits/stdc++.h>
#include <vector>
#include <string>

using namespace std;

class Num {
    vector<int> num;
public:
    Num() = default;

    Num(string &rhs);

    Num(Num &rhs);

    Num &operator=(Num &&rhs) noexcept;

    void Display();

    int Compare(Num &rhs);

    Num Add(Num &rhs);

    Num Minus(Num &rhs);
};

Num::Num(string &rhs) {
    int len = rhs.size();
    for (int i = len - 1; i >= 0; i--) {
        num.push_back(rhs[i] - '0');
    }
}

Num::Num(Num &rhs) {
    int len = rhs.num.size();
    for (int i = 0; i < len; i++) {
        num.push_back(rhs.num[i]);
    }
}

Num &Num::operator=(Num &&rhs) noexcept {
    int len = rhs.num.size();
    for (int i = 0; i < len; i++) {
        num.push_back(rhs.num[i]);
    }
    return *this;
}

void Num::Display() {
    int len = num.size();
    if (len == 1 && num[0] == 0) {
        cout << "0";
        return;
    }
    int tag = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (num[i] == 0 && tag == 0) {
            continue;
        }
        tag = 1;
        cout << num[i];
    }
}

int Num::Compare(Num &rhs) {
    int len1 = num.size(), len2 = rhs.num.size();
    if (len1 > len2) {
        return 1;
    } else if (len2 > len1) {
        return 2;
    } else if (len1 == len2) {
        for (int i = len1; i >= 0; i--) {
            if (num[i] < rhs.num[i]) {
                return 2;
            } else if (num[i] > rhs.num[i]) {
                return 1;
            }
        }
        return 0;
    }
    return 3;
}

Num Num::Add(Num &rhs) {
    int len1 = num.size(), len2 = rhs.num.size(), sum, ext = 0;
    Num rtn;
//    cout << "tag1";
    if (len1 <= len2) {
        for (int i = 0; i < len1; i++) {
            sum = num[i] + rhs.num[i] + ext;
            if (sum >= 10) {
                ext = sum / 10;
                sum %= 10;
                rtn.num.push_back(sum);
            } else {
                rtn.num.push_back(sum);
            }
        }
        for (int i = len1; i < len2; i++) {
            sum = rhs.num[i] + ext;
            if (sum >= 10) {
                ext = sum / 10;
                sum %= 10;
                rtn.num.push_back(sum);
            } else {
                rtn.num.push_back(sum);
            }
        }
        if (ext > 0) {
            rtn.num.push_back(ext);
        }
    } else if (len1 > len2) {
//        cout<<"tag";
        for (int i = 0; i < len2; i++) {
            sum = num[i] + rhs.num[i] + ext;
            if (sum >= 10) {
                ext = sum / 10;
                sum %= 10;
                rtn.num.push_back(sum);
            } else {
                rtn.num.push_back(sum);
            }
        }
        for (int i = len2; i < len1; i++) {
            sum = num[i] + ext;
            if (sum >= 10) {
                ext = sum / 10;
                sum %= 10;
                rtn.num.push_back(sum);
            } else {
                rtn.num.push_back(sum);
            }
        }
        if (ext > 0) {
            rtn.num.push_back(ext);
        }
    }
//    cout << "tag2";
//    rtn.Display();
//    cout << endl;
    return rtn;
}

Num Num::Minus(Num &rhs) {
    int len = rhs.num.size();
    for (int i = 0; i < len; i++) {
        num[i] -= rhs.num[i];
        if(num[i] < 0) {
            num[i + 1]--;
            num[i] += 10;
        }
    }
    return *this;
}

int main() {
    string n1, n2;
    cin >> n1 >> n2;
    Num num1(n1), num2(n2);
    int result = num1.Compare(num2);// 1 -> num1 > num2 ; 2 -> num2 > num1; 0 -> num1 == num2
    num1.Display();
    switch (result) {
        case 0:
            cout << "==";
            break;
        case 1:
            cout << ">";
            break;
        case 2:
            cout << "<";
            break;
        default:
            break;
    }
    num2.Display();
    cout << endl;
    num1.Add(num2).Display();
    cout << endl;
    switch (result) {
        case 0:
            cout << "0";
            break;
        case 1:
            num1.Minus(num2).Display();
            break;
        case 2:
            num2.Minus(num1).Display();
            break;
        default:
            break;
    }
    return 0;
}