#include <bits/stdc++.h>

using namespace std;

void Sort(long *s, int l, int r) {
    if (l >= r) {
        return;
    }
    long x = s[l];
    int i, j;
    i = l;
    j = r;
    while (i < j) {
        while (i < j && x <= s[j])
            j--;
        if (i < j) {
            s[i] = s[j];
            i++;
        }
        while (i < j && x > s[i])
            i++;
        if (i < j) {
            s[j] = s[i];
            j--;
        }
    }
    s[i] = x;
    Sort(s, l, i - 1);
    Sort(s, i + 1, r);
}

int main() {
    int m, n, k = 0, flag = 0, flag1 = 0;
    cin >> n >> m;
    long a[n], b[m], c[n + m];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] == a[i - 1]){
            n--;
            i--;
            continue;
        }
        c[k] = a[i];
        k++;
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        if(b[i] == b[i - 1]){
            m--;
            i--;
            continue;
        }
        c[k] = b[i];
        k++;
    }
    Sort(a, 0, n - 1);
    Sort(b, 0, m - 1);
    Sort(c, 0, k - 1);
    cout << "交:";
    for (int i = 0; i < n; i++) {
        if (a[i] == a[i - 1])
            continue;
        for (int j = 0; j < m; j++) {
            if (a[i] == b[j]) {
                cout << " ";
                cout << a[i];
                flag = 1;
            }
        }
    }
    if (flag == 0) {
        cout << "NULL";
    }
    cout << endl;
    flag = 0;
    cout << "并:";
    for (int i = 0; i < k; i++) {
        if (c[i] == c[i - 1])
            continue;
        cout << " " << c[i];
        flag = 1;
    }
    if (flag == 0)
        cout << "NULL";
    cout << endl;
    flag = 0;
    cout << "差:";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i] == b[j]) {
                flag1 = 1;
                break;
            }
        }
        if (flag1 == 0) {
            cout << " " << a[i];
            flag = 1;
        }
        flag1 = 0;
    }
    if (flag == 0)
        cout << "NULL";
    return 0;
}
