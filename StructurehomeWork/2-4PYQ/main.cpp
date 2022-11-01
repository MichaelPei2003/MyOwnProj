#include <bits/stdc++.h>

using namespace std;

int parent[30001];
int pyq[30001];

int Find(int x) {
    int flag = x;
    while (flag != parent[flag])    //parent node != self -> not root
        flag = parent[flag];        //move up
    //flag is root node now
    int i = x, tmp;
    while (flag != parent[i]) {     //Flat tree to make search easier
        tmp = parent[i];
        parent[i] = flag;
        i = tmp;
    }
    return flag;
}

void Union(int x, int y) {
    int rx = Find(x), ry = Find(y);
    if (rx == ry)
        return;
    parent[rx] = ry;                //trees combined
    pyq[ry] += pyq[rx];
}

int main() {
    int N, M, people, first, p;
    cin >> N >> M;
    for (int i = 0; i <= N; i++) {
        parent[i] = i;              //parent node = self
        pyq[i] = 1;                 //set pyq as nobody else
    }
    while (M--) {
        cin >> people;
        cin >> first;               //root of each club's tree
        while (--people) {          //to avoid only 1 person exists in club
            cin >> p;               //p is tag of every person
            Union(first, p);  //add p to club's tree
        }                           //pyq[first] added pyq[p]
    }
    int max = 0;
    for (int i = 0; i < N; i++) {
        if (pyq[i] > max)
            max = pyq[i];
    }
    cout << max;
    return 0;
}
