#include <bits/stdc++.h>

using namespace std;

typedef struct tree {
    char val;
    struct tree *lc;
    struct tree *rc;
} treeNode;

int leaf = 0;

treeNode *create() {
    treeNode *BT, *T;
    queue<treeNode *> q;
    char s;
    cin >> s;
    if (s != '#') {
        BT = (treeNode *) malloc(sizeof(treeNode));
        BT->val = s;
        BT->lc = BT->rc = nullptr;
        q.push(BT);
    } else {
        cout << 0;
        exit(0);
    }
    while (sizeof(q) != 0) {

    }
}

void front(treeNode *t) {
    if (t == nullptr) return;
    cout << t->val;
    front(t->lc);
    front(t->rc);
}

void middle(treeNode *t) {
    if (t == nullptr) return;
    middle(t->lc);
    cout << t->val;
    middle(t->rc);
}

void back(treeNode *t) {
    if (t == nullptr) return;
    back(t->lc);
    back(t->rc);
    cout << t->val;
}

int main() {
    treeNode *t = nullptr;
    t = create();
    if (t == nullptr) {
        cout << 0;
    } else {
        front(t);
        cout << endl;
        middle(t);
        cout << endl;
        back(t);
        cout << endl;
        cout << leaf;
    }
}
