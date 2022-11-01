#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, i, j;
    cin >> n >> k;
    int a[n];
    for (i = 0; i < n; i++)
        cin >> a[i];
    for (i = 0; i < k; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
    for (i = 0; i < n; i++) {
        if (i != 0) {
            cout << " ";
        }
        cout << a[i];
    }
}
