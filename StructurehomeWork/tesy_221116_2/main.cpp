#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, i, j, tmp, k;
    cin >> n;
    int a[n + 1];
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                tmp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = tmp;
            }
        }
        for (k = 0; k < n; k++) {
            if (k < n - 1) {
                cout << a[k] << " ";
            } else {
                cout << a[k] << endl;
            }
        }
    }
}
