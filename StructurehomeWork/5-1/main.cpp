#include <bits/stdc++.h>

using namespace std;

int main() {
    char a[33];
    cin >> a;
    int out[5];
    for (int i = 0; i < 4; i++) {
        int sum = 0;
        for (int j = 0; j < 8; j++) {
            sum += (a[i * 8 + j] - '0') * pow(2, 7 - j);
        }
        out[i] = sum;
    }
    cout << out[0] << "." << out[1] << "." << out[2] << "." << out[3];
}
