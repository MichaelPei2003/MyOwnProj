#include <bits/stdc++.h>

using namespace std;

typedef struct node {
    int data;
    struct node *next;
} node;

node *Create(int n) {
    node *head, *p, *q;
    head = (node *) malloc(sizeof(node));
    head->data = 1;
    head->next = nullptr;
    p = head;
    for (int i = 2; i <= n; i++) {
        q = (node *) malloc(sizeof(node));
        p->next = q;
        q->data = i;
        p = q;
    }
    p->next = head;
    return head;
}

void DeleteNext(node *p) {
    node *q = p->next;
    p->next = q->next;
    free(q);
}

int main() {
    int n, P, i = 0;
    cin >> n >> P;
    int rtn[n + 1];
    node *head, *p, *q;
    head = Create(n);
    p = head;
    while (i < n) {
        for (int j = 1; j < (P - 1); j++) {
            p = p->next;
        }
        q = p->next;
        rtn[i] = q->data;
        i += 1;
        DeleteNext(p);
        p = p->next;
    }
    for (i = 0; i < n - 1; i++) {
        cout << rtn[i] << " ";
    }
    cout << rtn[n - 1];
    return 0;
}
