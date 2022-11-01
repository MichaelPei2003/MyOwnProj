#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, i, j, tmp;
    cin >> n;
    int a[n];
    for (i = 0; i < n; i++)
        cin >> a[i];
    for (i = 0; i < n; i++) {
        tmp = i;
        for (j = i + 1; j < n; j++) {
            if (a[j] > a[tmp]) tmp = j;
        }
        swap(a[i], a[tmp]);
    }
    for (i = 0; i < n; i++) {
        if (i != 0) {
            cout << " ";
        }
        cout << a[i];
    }
}
