#include <bits/stdc++.h>

using namespace std;

int main() {
    char a[20][11];
    int i = 0;
    while (true) {
        cin >> a[i];
        if (a[i][0] == '#')
            break;
        i++;
    }
    int j, k;
    for (j = 0; j < i - 1; j++) {
        for (k = 0; k < i - j - 1; k++) {
            if (strlen(a[k - 1]) > strlen(a[k]))
                swap(a[k], a[k - 1]);
        }
    }
    for (j = 0; j < i; j++) {
        cout << a[j] <<" ";
    }
    return 0;
}
