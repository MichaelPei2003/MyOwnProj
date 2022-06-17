#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Num {
    vector<int> num;
public:
    Num();

    Num(string &tmp);

    Num(Num &rhs);

    ~Num() = default;

    void Display();

    Num Add(Num &rhs);

    int Compare(Num &rhs);

    void Minus(Num &rhs);
};

Num::Num(string &tmp) {
    int len = tmp.size();
    for (int i = len - 1; i >= 0; i--) {
        num.push_back(tmp[i]);
    }
}

Num::Num(Num &rhs) {
    int len = rhs.num.size();
    for (int i = len - 1; i >= 0; i--) {
        num.push_back(rhs.num[i]);
    }
}

void Num::Display() {
    int len = num.size();
    if (len == 1 && num[0] == 0) {
        cout << "0";
        return;
    }
    for (int i = len - 1; i >= 0; i--) {
        if (num[i] == 0) {
            continue;
        }
        cout << num[i];
    }
}

int Num::Compare(Num &tmp) {
    int rtn = 0;
    if(num.size() > tmp.num.size()) rtn = 1;
    else if(num.size() < tmp.num.size()) rtn = -1;
    else if(num.size() == tmp.num.size()){
        //逐位比较
        int len = num.size();
        for(int i = len - 1 ; i >= 0; i--){
            if(num[i] == tmp.num[i]) continue;
            else if(num[i] > tmp.num[i]){
                rtn = 1;
                break;
            }
            else{
                rtn = -1;
                break;
            }
        }
    }
    //根据f的值输出结果
    this->Display();
    if(rtn == 0) cout<<" == ";
    else if(rtn == 1) cout<<" > ";
    else if(rtn == -1) cout<<" < ";
    tmp.Display();
    return rtn;
}

Num Num::Add(Num &rhs) {
    int lenMin = num.size(), lenMax = rhs.num.size(), sum, ext = 0, tag = 0;// tag == 0 -> rhs>this
    Num rtn;
    if (lenMax < lenMin) {
        int tmp = lenMin;
        lenMin = lenMax;
        lenMax = tmp;
        tag = 1;
    }
    for (int i = 0; i < lenMin; i++) {
        sum = rhs.num[i] + num[i] + ext;
        ext = 0;
        if (sum >= 10) {
            ext = sum / 10;
            sum %= 10;
        }
        rtn.num.push_back(sum);
    }
    if (tag == 0) {
        for (int i = lenMin; i < lenMax; i++) {
            sum = num[i] + ext;
            ext = 0;
            if (sum >= 10) {
                ext = sum / 10;
                sum %= 10;
                rtn.num.push_back(sum);
            }
        }
    } else if (tag == 1) {
        for (int i = lenMin; i < lenMax; i++) {
            sum = rhs.num[i] + ext;
            ext = 0;
            if (sum >= 10) {
                ext = sum / 10;
                sum %= 10;
                rtn.num.push_back(sum);
            }
        }
    }
    if (ext != 0) {
        rtn.num.push_back(ext);
    }
    return rtn;
}

void Num::Minus(Num &tmp){
    //tmp为较小数
    //为了节省空间,直接在this上做减法
    int len = tmp.num.size();
    for(int i = 0; i < len; i++){
        num[i] -= tmp.num[i];
        if(num[i] < 0){
            num[i+1]--;
            num[i] += 10;
        }
    }
    this->Display();
}

int main() {
    string n1, n2;
    cin >> n1 >> n2;
    Num num1(n1), num2(n2);
    int rst = num1.Compare(num2);
    cout << endl;
    num1.Add(num2).Display();
    cout << endl;
    if (rst == 1) {
        num2.Minus(num1);
    } else if (rst == 2) {
        num1.Minus(num2);
    } else {
        cout << "0";
    }
};
