#include <bits/stdc++.h>

using namespace std;

typedef struct node {
    int data;
    struct node *left, *right;
} TNode, *BiTree;

const int maxN = 220;
int BST[maxN];
int m, n;

void BuildTree(BiTree &T, int x) {
    if (T == nullptr) {
        T = (BiTree) malloc(sizeof(BiTree));
        T->data = x;
        T->left = nullptr;
        T->right = nullptr;
    } else if (x < T->data) {
        BuildTree(T->left, x);
    } else if (x > T->data) {
        BuildTree(T->right, x);
    }
}

bool Search_BST(BiTree &T, int x) {
    if (T == nullptr || T->data == x)
        return true;
    if (T->data > x)
        return Search_BST(T->left, x);
    else
        return Search_BST(T->right, x);
}

int GetValue(BiTree &T) {
    if (T == nullptr)
        return -1;
    return T->data;
}

bool IsParent(BiTree &T, int x, int y) {
    if (T == nullptr)
        return false;
    if (T->data == x) {
        if (GetValue(T->left) == y || GetValue(T->right) == y)
            return true;
    }
    return IsParent(T->left, x, y) || IsParent(T->right, x, y);
}

bool IsLChild(BiTree &T, int x, int y) {
    if (T == nullptr)
        return false;
    if (T->data == y) {
        if (GetValue(T->left) == x)
            return true;
    }
    return IsLChild(T->left, x, y) || IsLChild(T->right, x, y);
}

bool IsRChild(BiTree &T, int x, int y) {
    if (T == NULL)
        return false;
    if (T->data == y) {
        if (GetValue(T->left) == x || GetValue(T->right) == x)
            return true;
    }
    return IsRChild(T->left, x, y) || IsRChild(T->right, x, y);
}

void Depth(BiTree &T, int e, int h, int &c) {
    if (T == nullptr)
        return;
    if (T->data == e) c = h;
    Depth(T->left, e, h + 1, c);
    Depth(T->right, e, h + 1, c);
}

bool Compare(BiTree &T, int x, int y) {
    int f1, f2;
    Depth(T, x, 0, f1);
    Depth(T, x, 0, f2);
    if (f1 = f2)
        return true;
    return false;
}

bool IsBrother(BiTree &T, int x, int y) {
    if (T == nullptr)
        return false;
    if (T->left != nullptr && T->right != nullptr) {
        if (T->left->data == x && T->right->data == y)
            return true;
        if (T->left->data == y && T->right->data == x)
            return true;
    }
    IsBrother(T->left, x, y);
    IsBrother(T->right, x, y);
}

bool IsInTree(int x) {
    for (int i = 0; i < n; i++) {
        if (x == BST[i])
            return true;
    }
    return false;
}

int main() {
    cin >> n;
    BiTree T = nullptr;
    int i;
    for (i = 0; i < n; i++)
        cin >> BST[i];
    for (i = 0; i < n; i++)
        BuildTree(T, BST[i]);
    cin >> m;
    int _a, _b, _c;
    string a, b, c;
    while (m--) {
        cin >> _a;
        cin >> a;
        if (a == "is") {
            cin >> a >> b;
            if (b == "parent") {
                cin >> c >> _b;
                if (IsParent(T, _a, _b) && IsInTree(_a) && IsInTree(_b))
                    cout << "Yes" << endl;
                else
                    cout << "No" << endl;
                continue;
            } else if (b == "left") {
                cin >> b >> c;
                cin >> _b;
                if (IsLChild(T, _a, _b) && IsInTree(_a) && IsInTree(_b))
                    cout << "Yes" << endl;
                else
                    cout << "No" << endl;
                continue;
            } else if (b == "right") {
                cin >> b >> c;
                cin >> _b;
                if (IsRChild(T, _a, _b) && IsInTree(_a) && IsInTree(_b))
                    cout << "Yes" << endl;
                else
                    cout << "No" << endl;
                continue;
            } else if (b == "root") {
                if (T != nullptr && T->data == _a && IsInTree(_a))
                    cout << "Yes" << endl;
                else
                    cout << "No" << endl;
                continue;
            }
        } else if (a == "and") {
            cin >> _b;
            cin >> b >> c;
            if (c == "siblings") {
                if (IsBrother(T, _a, _b) && IsInTree(_a) && IsInTree(_b))
                    cout << "Yes" << endl;
                else
                    cout << "No" << endl;
                continue;
            } else {
                getline(cin, b);
                if (Compare(T, _a, _b) && IsInTree(_a) && IsInTree(_b))
                    cout << "Yes" << endl;
                else
                    cout << "No" << endl;
                continue;
            }
        }
    }
    return 0;
}
