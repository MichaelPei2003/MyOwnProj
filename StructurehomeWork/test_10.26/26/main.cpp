#include <bits/stdc++.h>

using namespace std;


int main() {
    int N, x;
    int yrs[52] = {0};
    cin >> N;
    while (N--) {
        cin >> x;
        yrs[x]++;
    }
    for (int i = 0; i < 51; i++) {
        if (yrs[i] == 0)
            continue;
        cout << i << ":" << yrs[i] << endl;
    }
}
