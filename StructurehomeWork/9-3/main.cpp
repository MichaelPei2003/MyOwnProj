#include <bits/stdc++.h>

using namespace std;

int main() {
    long x, f;
    int flag = 0, N, n;
    cin >> N >> x;
    n = N;
    while (N--) {
        cin >> f;
        if (f == x) {
            cout <<n - N - 1;
            flag = 1;
        }
    }
    if (flag == 0)
        cout << "Not Found";
    return 0;
}
