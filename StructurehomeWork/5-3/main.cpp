#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a[100000];
    int sum = 0, maxSum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        if (sum > maxSum) {
            maxSum = sum;
        } else if (sum < 0) {
            sum = 0;
        }
    }
    cout << maxSum;
    return 0;
}
