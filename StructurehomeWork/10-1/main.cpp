#include <bits/stdc++.h>

using namespace std;

typedef struct stu {
    char id[14];
    int score;
    int place;
} stu;

stu a[30000];

bool IsHigher(char *s1, char *s2) {
    for (int i = 0; i < 13; i++) {
        if (s1[i] > s2[i])
            return true;
        else if (s1[i] < s2[i])
            return false;
    }
    return true;
}

void Sort(int l, int r) {
    if (l >= r)
        return;
    int i = l, j = r;
    stu t = a[l];
    while (i != j) {
        while (i < j && (a[j].score < t.score || (a[j].score == t.score && IsHigher(a[j].id, t.id))))
            j--;
        while (i < j && (a[i].score > t.score || a[i].score == t.score && IsHigher(t.id, a[i].id)))
            i++;
    }
    if (i < j)
        swap(a[i], a[j]);
    a[l] = a[i];
    a[i] = t;
    Sort(l, i - 1);
    Sort(i + 1, r);
}

void Cpy(int *b2, int *b1, int n) {
    for (int i = 1; i <= n; i++)
        b2[i] = b1[i];
}

int main() {
    int n, j, i, top = 0;
    for (i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for (j = 0; j < k; j++) {
            cin >> a[top].id >> a[top].score;
            a[top].place = i;
            top++;
        }
    }
    Sort(0, top - 1);
    int levall = 1, b1[n + 1], b2[n + 1], score = a[0].score;
    for (i = 1; i <= n; i++) {
        b1[i] = 1, b2[i] = 1;
    }
    cout << top << endl;
    cout << a[0].id << " " << a[0].place << 1;
    int llevall = 1;
    levall = 2;
    Cpy(b2, b1, n);
    b1[a[0].place]++;
    for (i = 1; i < top; i++) {
        if(a[i].score == a[i-1].score)
        {
            printf("%s %d %d %d\n",a[i].id,llevall,a[i].place,b2[a[i].place]);
            levall++;
            b1[a[i].place]++;
        }
        else
        {
            printf("%s %d %d %d\n",a[i].id,levall,a[i].place,b1[a[i].place]);
            llevall = levall;
            levall++;

            Cpy(b2,b1,n);
            b1[a[i].place]++;
        }
    }
    return 0;
}
