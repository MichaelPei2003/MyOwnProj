#include <bits/stdc++.h>

using namespace std;

int person[1000] = {0};
int group[1000] = {0};
int parent[1000];

bool cmp(int x, int y) {
    return x > y;
}

int Find(int x) {
    int flag = x;
    while (flag != parent[flag])
        flag = parent[flag];
    int i = x, tmp;
    while (flag != parent[i]) {
        tmp = parent[i];
        parent[i] = flag;
        i = tmp;
    }
    return flag;
}

void Connect(int x, int y) {
    int rx = Find(x), ry = Find(y);
    if (rx != ry) {
        parent[rx] = ry;
    }
}

int main() {
    int N, num, x, cnt = 0;
    cin >> N;
    char ch;
    for (int i = 0; i < 1000; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < N; i++) {
        cin >> num >> ch >> person[i];      //mark every person using their first interest
        while (--num) {
            cin >> x;
            Connect(person[i], x);
        }
    }
    for (int i = 0; i < N; i++)
        group[Find(person[i])]++;
    for (int i = 0; i < 1000; i++) {
        if (group[i] != 0) {
            cnt++;
        }
    }
    cout << cnt << endl;
    sort(group, group + 1000, cmp);
    for (int i = 0; i < cnt; i++) {
        if (i != 0)
            cout << " ";
        cout << group[i];
    }
}
