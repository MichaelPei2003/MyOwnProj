#include <stdio.h>
#include <malloc.h>

typedef struct Node {
    struct Node *next;
    int value;
    int index;
} List;

int main() {
    List *pHead = (List *) malloc(sizeof(List));
    List *pTail = (List *) malloc(sizeof(List));
    pHead->next = pTail;
    pTail->next = NULL;
    int val, ind, cnt = 0;
    while (scanf("%d %d", &val, &ind) != EOF) {
//    while (cnt < 2) {
//        scanf("%d %d", &val, &ind);
        List *node = (List *) malloc(sizeof(List));
        node->value = val;
        node->index = ind;
        node->next = pHead->next;
        pHead->next = node;
        cnt++;
    }
    List *node, *tmp;
    node = pHead->next;
    if (pHead->next->index == 0) {
        if(cnt == 1) {
            printf("0 0");
            exit(0);
        }
        node = node->next;
        free(pHead);
        cnt--;
    }
    int a[cnt], b[cnt], i;
    for (i = 0; i <= cnt; i++) {
        a[i] = node->value * node->index;
        b[i] = node->index - 1;
        tmp = node;
        node = node->next;
        free(tmp);
    }
    for (i = cnt - 1; i >= 0; i--) {
        printf("%d %d", a[i], b[i]);
        if (i != 0) {
            printf(" ");
        }
    }
    return 0;
}
