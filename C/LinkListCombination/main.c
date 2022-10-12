#include <stdio.h>
#include <malloc.h>

typedef struct node {
    struct node *next;
    int data;
} *List;

List ReadData() {
    int x;
    List pHead = (List) malloc(sizeof(List));
    pHead->next = NULL;
    List p;
    p = pHead;
    while (~scanf("%d", &x) && x != -1) {
        List node = (List) malloc(sizeof(List));
        node->data = x;
        node->next = NULL;
        p->next = node;
        p = node;
    }
    return pHead;
}

void Merge(List a, List b) {
    a = a->next;
    b = b->next;
    List pHead = (List) malloc(sizeof(List));
    pHead->next = NULL;
    List q = pHead;
    while (a || b) {
        List p = (List) malloc(sizeof(List));
        p->next = NULL;
        if (a == NULL || a->data > b->data) {
            p->data = b->data;
            b = b->next;
            q->next = p;
            q = p;
        } else {
            p->data = a->data;
            a = a->next;
            q->next = p;
            q = p;
        }
    }
    List n = pHead;
    n = n->next;
    if (n == NULL) {
        printf("NULL");
    }
    while (n) {
        if (n->next && n->data == n->next->data) {
            n = n->next;
            continue;
        }
        printf("%d", n->data);
        if (n->next != NULL) {
            printf(" ");
        }
        n = n->next;
    }
}

int main() {
    List a = ReadData();
    List b = ReadData();
    Merge(a, b);
    return 0;
}
