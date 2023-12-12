#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include "RexpToNFA.h"

using namespace std;

int main() {
    RTN rt;
    cout << "有效的正规式的字母表∑={a-z,A-Z}，辅助字母表∑={'*','|','(',')','.'}" << endl;
    cout << "'*'   表示闭包" << endl << "'|'   表示联合" << endl << "'.'   表示连接" << endl;
    while (1) {
        cout << "\n请输入一个正规式:";
        string s = "";
        cin >> s;
        if (rt.islegal(s)) {
            cout << "输入的正规式合法！" << endl;
            string ss = rt.turnToConnect(s);
            cout << "补缺省略的连接符号'.'之后为：" << ss << endl;
            cout << "对应的后缀表达式为：" << rt.ReversePolishType(ss);
            string rs = rt.ReversePolishType(ss);
            rt.PolishTypeToNFA(rs);
        } else {
            cout << "输入的正规式不合法！" << endl << "请重新输入：";
        }
    }
}
