#include <bits/stdc++.h>

using namespace std;

int main() {
    char c;
    int blank = 0, digit = 0, other = 0;
    while (scanf("%c", &c) && c != '\n') {
        if (c == ' ') {
            blank++;
        } else if (c >= '0' && c <= '9') {
            digit++;
        } else {
            other++;
        }
    }
    cout << "blank = " << blank << ", " << "digit = " << digit << ", " << "other = " << other;
}
