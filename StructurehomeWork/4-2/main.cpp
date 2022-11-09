#include <bits/stdc++.h>

using namespace std;

int a[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
char b[18] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2',};

int main() {
    int x, cnt = 0;
    cin >> x;
    getchar();
    while (x--) {
        char n[18];
        int flag = 0, code = 0;
        cin >> n;
        for (int i = 0; i < 17; i++) {
            if (n[i] > '9' || n[i] < '0') {
                flag = 1;
            }
            code += (n[i] - '0') * a[i];
        }
        code = code % 11;
        if (n[17] != b[code] || flag == 1) {
            cnt++;
            cout << n << endl;
        }
    }
    if (cnt == 0) {
        cout << "All passed";
    }
}
