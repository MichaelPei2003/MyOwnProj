#include <bits/stdc++.h>

using namespace std;

int main() {
    int D, P;
    cin >> D >> P;
    if (P == 3)
        cout << D - 1;
    else
        cout << D - (P / 2 + 1);
    return 0;
}
