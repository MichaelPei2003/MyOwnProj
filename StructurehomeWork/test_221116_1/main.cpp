#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, i, j, flag = 0;
    cin >> n >> m;
    int a[30001] = {0};
    for (i = 0; i < n; i++) {
        cin >> j;
        a[j] = 1;
    }
    for (i = 0; i < m; i++) {
        cin >> j;
        a[j] = 0;
    }
    for (i = 1; i < 30001; i++) {
        if (a[i] == 1) {
            flag = 1;
        }
    }
    if (flag == 0) {
        cout << 0;
    } else {
        for (i = 1; i < 30001; i++) {
            if (a[i] == 1) {
                cout << i << " ";
            }
        }
    }
    return 0;
}
