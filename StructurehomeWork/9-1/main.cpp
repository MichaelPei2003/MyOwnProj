#include <bits/stdc++.h>

using namespace std;

int main() {
    char x, a[80], ch;
    int cnt = 0;
    cin >> x;
    fflush(stdin);
    ch = getchar();
    for (int i = 0; ch != '\n'; i++) {
        a[i] = ch;
        cnt++;
        ch = getchar();
    }
    int n = -1;
    for(int i = cnt - 1; i >= 0; i--) {
        if(a[i] == x) {
            n = i;
            break;
        }
    }
    if(n == -1)
        cout<<"Not Found";
    cout << "index = " << n;
    return 0;
}
