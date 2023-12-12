#include <iostream>
#include <queue>

using namespace std;

const int maxn = 2048;
//lft[]a所经过的集合, rig[]b所经过的集合,nul[]&所经过的集合
int a[maxn], b[maxn], kong[maxn], lft[maxn], rgt[maxn], nul[maxn];
//change[]将nfa转dfa
char changea[maxn], changeb[maxn], changekong[maxn];
int count1 = 0, count2, q, p;

int index(int p) {//找到对应的状态下标
    int x = 1;
    if (p == 1)
        return 0;
    int i = 0;

    while (++i) { //循环找出当前对应的状态下标
        x <<= 1;
        if (p == x)
            return i; //找到即返回对应下标
    }
    return 0;
}

int moveT(int a, int b) {
    while (b) {
        int x = b & (-b); //取当前集合中的最后一个节点
        if (!(a & x)) //如果不存在该节点，加入集合当中
            a ^= x;
        b ^= x;  //已经存在该节点，就进行舍去操作
    }
    return a;
}

void nfakong(int p, char tchar) {
    int nt = 0;
    while (p) {
        int x = p & (-p); //取出当前集合中的最后一个节点
        int y = index(x); //找到对应的状态下标
        if (kong[y] != 0) {
            if (tchar == 'a') {
                lft[count1] |= kong[y];
            } else if (tchar == 'b') {
                rgt[count1] |= kong[y];
            } else if (tchar == '&') {
                nul[count1] |= kong[y];
            }
            nt = moveT(nt, kong[y]); //进行move操作
        }
        p ^= x;   //将当前拿出来的节点从原集合中去掉
    }
    if (nt != 0) {
        if (tchar == 'a') {
            nfakong(nt, 'a'); //进行重复操作
        } else if (tchar == 'b') {
            nfakong(nt, 'b'); //进行重复操作
        } else {
            nfakong(nt, '&'); //进行重复操作
        }
    }
}

void nfa(int p) {
    int lsum = 0, rsum = 0;
    while (p) {
        int x = p & (-p); //取出当前集合中的最后一个节点
        int y = index(x); //找到对应的状态下标
        if (a[y] != 0) {
            lsum = moveT(lsum, a[y]); //进行move操作
        }
        if (b[y] != 0) {
            rsum = moveT(rsum, b[y]);  //进行move操作
        }
        p ^= x;   //将当前拿出来的节点从原集合中去掉
    }
    lft[count1] = lsum;  //更新当前的状态集合
    rgt[count1] = rsum;  //更新当前的状态集合
    if (lsum) {
        nfakong(lsum, 'a'); //进行重复操作
    }
    if (rsum) {
        nfakong(rsum, 'b'); //进行重复操作
    }
}

void jihe(int p) {
    while (p) {
        int x = p & (-p); //取出当前集合中的最后一个节点
        int y = index(x); //找到对应的状态下标
        cout << y;
        p ^= x;   //将当前拿出来的节点从原集合中去掉
        if (p != 0) {
            cout << ",";
        }
    }
}

int main() {
    int t;
    cout << "请先输入对应的行数:" << endl;
    cin >> t;
    cout << "请输入NFA(&代表空串):" << endl;
    while (t--) {
        int preNode, nexNode;
        char tchar;
        cin >> preNode >> tchar >> nexNode;
        if (tchar == 'a') {
            a[preNode] |= (1 << nexNode);
        } else if (tchar == 'b') {
            b[preNode] |= (1 << nexNode);
        } else {
            kong[preNode] |= (1 << nexNode);
        }
    }
    cout << endl;
    cout << "开始状态:";
    cin >> q;
    cout << "接受状态:";
    cin >> p;
    cout << endl;
    //I初始状态
    nul[count1] = kong[q];
    nfakong(kong[q], '&');   //开始转换
    nul[count1] |= (1 << q);
    nfa(nul[count1]);
    count2 = count1;
    int f, m;
    while (count1 >= count2) {
        f = 0, m = 0;
        count1++;  //lef[]输入到nul[],左一次
        while (f < count1) {  //判断是否重复
            if (lft[count2] == nul[f]) {
                m = 1;
                break;
            }
            f++;
        }
        if (m == 0) {
            if (lft[count2] == NULL) {
                count1--;
            } else {
                nul[count1] = lft[count2];
                nfa(lft[count2]);
            }
        } else {
            m = 0;
            count1--;
        }
        count1++;//rgt[]输入到nul[],右一次
        f = 0, m = 0;
        while (f < count1) {  //判断是否重复
            if (rgt[count2] == nul[f]) {
                m = 1;
                break;
            }
            f++;
        }
        if (m == 0) {
            if (rgt[count2] == NULL) {
                count1--;
            } else {
                nul[count1] = rgt[count2];
                nfa(rgt[count2]);
            }
        } else {
            m = 0;
            count1--;
        }
        count2++;
    }
    cout << endl;
    //输出nfa
    cout << "NFA状态矩阵:" << endl;
    cout << "--------------------------------------------------------------------" << endl;
    cout << "I初始状态" << "		" << "Ia" << "			" << "Ib" << endl;
    cout << "--------------------------------------------------------------------" << endl;
    for (int i = 0; i < count2; i++) {
        jihe(nul[i]);
        cout << "		";
        jihe(lft[i]);
        cout << "		";
        jihe(rgt[i]);
        cout << endl;
        changekong[i] = 'A' + i; //将对应的nul[]标记字符
    }
    cout << endl;
    //输出dfa
    for (int i = 0; i < count2; i++) {
        for (int j = 0; j < count2; j++) {
            if (lft[i] == nul[j]) {
                changea[i] = changekong[j];
            }
            if (rgt[i] == nul[j]) {
                changeb[i] = changekong[j];
            }
        }
    }
    cout << endl;
    cout << "由NFA得到的DFA状态转换矩阵:" << endl;
    cout << "-------------------------" << endl;
    cout << "I" << "	" << "Ia" << "	" << "Ib" << endl;
    cout << "-------------------------" << endl;
    for (int i = 0; i < count2; i++) {
        cout << changekong[i] << "	" << changea[i] << "	" << changeb[i] << endl;
    }
    return 0;
}