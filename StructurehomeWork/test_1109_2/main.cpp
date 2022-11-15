#include <bits/stdc++.h>

using namespace std;

float f(float x);

float a3, a2, a1, a0;

int main() {
    float a, b;
    cin >> a3 >> a2 >> a1 >> a0;
    cin >> a >> b;
    float left, mid, right;
    left = a;
    right = b;
    while (left <= right - 0.001 && f(left) * f(right) <= 0) {
        if (f(left) == 0) {
            cout << fixed << setprecision(2) << left;
            return 0;
        }
        if (f(right) == 0) {
            cout << fixed << setprecision(2) << right;
            return 0;
        }
        mid = (left + right) / 2;
        if (f(mid) * f(left) > 0) {
            left = mid;
        } else {
            right = mid;
        }
    }
    cout << fixed << setprecision(2) << mid;
    return 0;
}

float f(float x) {
    float result;
    result = a3 * x * x * x + a2 * x * x + a1 * x + a0;
    return result;
}