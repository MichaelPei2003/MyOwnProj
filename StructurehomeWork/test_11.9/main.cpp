#include <bits/stdc++.h>

using namespace std;

void Find(long x, int left, int right, int mid, long a[]) {
    cout << "[" << left << "," << right << "]" << "[" << mid << "]" << endl;
    if (left == right && right == mid && x != a[mid]) {
        cout<<"Not Found";
        exit(0);
    }
    if (x < a[mid]) {
        right = mid - 1;
        mid = (left + right) / 2;
        Find(x, left, right, mid, a);
    } else if (x > a[mid]) {
        left = mid + 1;
        mid = (left + right) / 2;
        Find(x, left, right, mid, a);
    } else if (x == a[mid]) {
        cout << mid;
    }
}

int main() {
    int n;
    long x;
    cin >> n >> x;
    long a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == a[i - 1]) {
            cout << "Invalid Value";
            return 0;
        }
    }
    Find(x, 0, n - 1, (n - 1) / 2, a);
}
