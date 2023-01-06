#include <bits/stdc++.h>

using namespace std;

int n, e;

vector<int> v[1005];
int book[1005];
int flag = 0;
int minStep = 0x7fffffff;

void dfs(int a, int b, int step) {
    if (a == b) {
        flag = 1;
        if (step < minStep)
            minStep = step;
        return;
    }
    int len = v[a].size();
    for (int i = 0; i < len; i++) {
        if (book[v[a][i]] == 0) {
            book[v[a][i]] = 1;
            if (step + 1 < minStep)
                dfs(v[a][i], b, step + 1);
            book[v[a][i]] = 0;
        }
    }
}

int main() {
    cin >> n >> e;
    for (int i = 1; i <= e; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 0; i < n; i++) {
        sort(v[i].begin(), v[i].end());
    }
    int a, b;
    cin >> a >> b;
    dfs(a, b, 0);
    if (flag) {
        cout << "The length of the shortest path between " << a << " and " << b << " is " << minStep << ".";
    } else cout << "There is no path between " << a << " and " << b << ".";
    return 0;
}
