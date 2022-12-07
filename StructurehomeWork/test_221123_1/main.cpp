#include <bits/stdc++.h>

using namespace std;
int n;

void Print(int a[]) {
    for (int k = 0; k < n; k++) {
        cout << a[k];
        if (k != n - 1) {
            cout << " ";
        }
    }
}

void swap(int *a, int i, int j) {
    int tmp;
    tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

void QuickSort(int *a, int l, int r) {
    int base = a[l];
    int i = l, j = r;
    if (l >= r) {
        return;
    }
    while (i != j) {
        while (a[j] >= base && i < j) {
            j--;
        }
        while (a[i] <= base && i < j) {
            i++;
        }
        if (j > i) {
            swap(a, i, j);
        }
    }
    swap(a, l, i);
    Print(a);
    cout << endl;
    QuickSort(a, l, i - 1);
    QuickSort(a, i + 1, r);
}

int main() {
    cin >> n;
    int a[n];
    int i, j;
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }
    i = 0;
    j = n - 1;
    QuickSort(a, i, j);
    Print(a);
    return 0;
}
