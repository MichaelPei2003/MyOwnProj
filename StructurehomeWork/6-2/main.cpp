#include <bits/stdc++.h>

using namespace std;
int n;

int Find(int *a, int x) {
    for (int i = 0; i < n; i++) {
        if (a[i] == x) return i;
    }
}

void PrintFRT(int *back, int *mid, int p) {
    if (p >= 0) {
        cout << " " << back[p];
        int root = Find(mid, back[p]);
        int L1[n], L2[n], R1[n], R2[n];
        for (int i = 0; i < root; i++) {
            L1[i] = back[i];
            L2[i] = mid[i];
        }
        for (int i = root; i < p; i++) {
            R1[i - root] = back[i];
        }
        for (int i = root + 1; i < p + 1; i++) {
            R2[i - root - 1] = mid[i];
        }
        PrintFRT(L1, L2, root - 1);
        PrintFRT(R1, R2, p - root - 1);
    }
}

int main() {
    cin >> n;
    int back[n], mid[n];
    for (int i = 0; i < n; i++) {
        cin >> back[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> mid[i];
    }
    cout << "Preorder:";
    PrintFRT(back, mid, n - 1);
}
