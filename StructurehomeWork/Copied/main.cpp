#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
string S, T;
int Next[N];
void get_next()
{
    int i = 0, j = -1;
    Next[i] = -1;
    while (i < T.size())
    {
        if (j == -1 || T[i] == T[j])
        {
            Next[++i] = ++j;
        }
        else
            j = Next[j];
    }
}

int kmp(int pos)
{
    int i = pos, j = 0, ans = 0;
    while (i < S.size())
    {
        if (S[i] == T[j] || j == -1)
            ++i, ++j;
        else
            j = Next[j];
        if (j == T.size())
        {
            ans++;
            if (ans == 1)
                cout << i - j + 1 << " ";
            // j = Next[j - 1];
            // i--;
            j = Next[j];
        }
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> S;
        cin >> T;
        get_next();
        int ans = kmp(0);
        if (ans == 0)
            cout << "0 0" << endl;
        else
            cout << ans << endl;
    }

    return 0;
}