#include <bits/stdc++.h>

using namespace std;

int parent[30001];
int pyq[30001];

int Find(int x) {
    int flag = x;
    while (flag != parent[flag])//parent node != self -> not root
        flag = parent[flag];    //move up
    //flag is root node now
    int i = x, tmp;
    while(flag != parent[x]){

    }
}

void Union(int x, int y) {
    
}

int main() {
    int N, M, num, first, p;
    cin >> N >> M;
    for (int i = 0; i <= N; i++) {
        parent[i] = i;              //parent node = self
        pyq[i] = 1;                 //set pyq as nobody else
    }
    while (M--) {
        cin >> num;
        cin >> first;               //root of each club's tree
        while (num--) {
            cin >> p;
            
        }
    }
}
