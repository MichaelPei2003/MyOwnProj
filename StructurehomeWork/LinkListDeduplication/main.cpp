#include <bits/stdc++.h>

using namespace std;

int main() {
    int data[100000], pNext[100000], Loc, nodeData, num, next, i, j, k = 0, flag1 = 0, flag2 = 0;
    string pHead;
    cin >> pHead >> num;
    int Tmp[num + 1], Data[num + 1];
    string addr[num + 1], del[num + 1];
    for (i = 0; i < num; i++) {
        cin >> Loc >> nodeData >> next;
        data[Loc] = nodeData;
        pNext[Loc] = next;
    }
    flag1 = stoi(pHead);
    for (i = 0; i < num; i++) {
        addr[i] = to_string(flag1);
        Data[i] = data[flag1];
        flag1 = pNext[flag1];
    }
//    --------------------------------------------
/*    flag1 = stoi(addr[0]);
    for (i = 0; i < num; i++) {
        if (addr[i] == "-2") {
            continue;
        }
        printf("%05d", stoi(addr[i]));
        cout << " " << data[flag1] << " ";
        if (pNext[flag1] == -1) {
            cout << -1;
            break;
        }
        printf("%05d\n", pNext[flag1]);
        flag1 = pNext[flag1];
    }
*/
//    ---------------------------------------------
    for (i = 0; i < num; i++) {
        for (j = i + 1; j < num; j++) {
            if (Data[i] == Data[j] || Data[i] == -Data[j]) {
                if (flag2 != 0) {
                    if (j + 1 >= num) {
                        pNext[stoi(addr[j - 1])] = -1;
                    } else {
                        pNext[stoi(addr[j - 1])] = pNext[stoi(addr[j])];
                    }
                }
                del[flag2] = addr[j];
                addr[j] = "-2";
                flag2++;
            }
        }
    }
//    ---------------------------------------------
    flag1 = stoi(pHead);
    for (i = 0; i < num; i++) {
        if (addr[i] == "-2") {
            continue;
        }
        printf("%05d", stoi(addr[i]));
        cout << " " << data[flag1] << " ";
        if (pNext[flag1] == -1) {
            cout << -1;
            break;
        }
        printf("%05d\n", pNext[flag1]);
        flag1 = pNext[flag1];
    }
}
