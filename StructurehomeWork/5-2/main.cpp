#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    int i, j;
    int a[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, b[11], c[10];
    cin >> s;
    for (i = 0; i < 11; i++) {
        switch (s[i]) {
            case '0':
                a[0] = 1;
                break;
            case '1':
                a[1] = 1;
                break;
            case '2':
                a[2] = 1;
                break;
            case '3':
                a[3] = 1;
                break;
            case '4':
                a[4] = 1;
                break;
            case '5':
                a[5] = 1;
                break;
            case '6':
                a[6] = 1;
                break;
            case '7':
                a[7] = 1;
                break;
            case '8':
                a[8] = 1;
                break;
            case '9':
                a[9] = 1;
                break;
            default:
                break;
        }
    }
    int k = 0, n = 0;
    for (i = 0; i < 10; i++) {
        if (a[i] == 1)
            n++;
    }
    cout << "int[] arr = new int[]{";
    for (i = 9; i >= 0; i--) {
        if (a[i] == 1 && k < n - 1) {
            cout << i << ",";
            c[k] = i;
            k++;
        } else if (a[i] == 1) {
            cout << i;
            c[k] = i;
            k++;
        }
    }
    cout << "};" << endl;
    cout << "int[] index = new int[]{";
    for (i = 0; i < s.length(); i++) {
        for (j = 0; j < k; j++) {
            if (s[i] - '0' == c[j] && i < 10) {
                cout << j << ",";
            } else if (s[i] - '0' == c[j]) {
                cout << j;
            }
        }
    }
    cout << "};" << endl;
    return 0;
}
