#include <bits/stdc++.h>

using namespace std;

typedef struct node {
    int addr;
    int data;
    int next;
} List;

int main() {
    List node[100001];
    int flag[100001], newList[100001] = {0}, del[100001];
    int pHead, n, i, j = 0, k = 0, addr, data, next;
    cin >> pHead >> n;
    for (i = 0; i < n; i++) {
        cin >> addr >> data >> next;
        node[addr].addr = addr;
        node[addr].data = data;
        node[addr].next = next;
    }
    addr = pHead;
    while (addr != -1) {
        int data = fabs(node[addr].data);
        if (flag[data] == 0) {                      // if this data is not marked
            newList[j++] = addr;                    //add it to newList, j counts length of newList
            flag[data] = 1;                         //mark this data
        } else {
            del[k++] = addr;                        //if data is marked, add to del, k counts length of del
        }
        addr = node[addr].next;
    }
    //print newList
    for (i = 0; i < j; i++) {
        if (i == j - 1)                             //pTail reached
            printf("%05d %d -1\n", newList[i], node[newList[i]].data);
        else
            printf("%05d %d %05d\n", newList[i], node[newList[i]].data, node[newList[i + 1]].addr);
    }
    //print del
    for (i = 0; i < k; i++) {
        if (i == k - 1)
            printf("%05d %d -1\n", del[i], node[del[i]].data);
        else
            printf("%05d %d %05d\n", del[i], node[del[i]].data, node[del[i + 1]].addr);
    }
}
