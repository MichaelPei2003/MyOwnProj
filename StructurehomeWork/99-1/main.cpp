#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, max = 0;
    cin >> n;
    int a[n], box[1001] = {0};
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cout << a[i];
        for (int j = 0; j < 1000; j++) {
            if (box[j] + a[i] <= 100) {
                box[j] += a[i];
                cout << " " << j + 1 << endl;
                if (j + 1 > max) {
                    max = j + 1;
                }
                break;
            }
        }
    }
    cout << max;
    return 0;
}
