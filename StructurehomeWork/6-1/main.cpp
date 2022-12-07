#include <bits/stdc++.h>

using namespace std;

typedef struct node {
    int lc;
    int rc;
} node;

int main() {
    int arr[10] = {0}, n, i, root;
    node T[10];
    char lc, rc;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> lc >> rc;
        if (lc == '-') {
            T[i].lc = -1;
        } else {
            T[i].lc = lc - '0';
            arr[T[i].lc] = 1;
        }
        if (rc == '-') {
            T[i].rc = -1;
        } else {
            T[i].rc = rc - '0';
            arr[T[i].rc] = 1;
        }
    }
    for (i = 0; i < n; i++) {
        if (!arr[i]) {//unmarked pointer pointed to root node
            root = i;
            break;
        }
    }
    queue<int> q;
    q.push(root);
    int flag = 0;
    while (q.size() > 0) {
        root = q.front();
        q.pop();
        if (T[root].lc == -1 && T[root].rc == -1) {
            if (flag)
                cout << " ";
            cout << root;
            flag = 1;
        } else {
            if(T[root].lc != -1)
                q.push(T[root].lc);
            if(T[root].rc != -1)
                q.push(T[root].rc);
        }
    }
    return 0;
}
