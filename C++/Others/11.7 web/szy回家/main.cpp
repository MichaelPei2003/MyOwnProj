#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    long long n,s;
    s=1;
    cin>>n;
    long long i,a[n+1]={1};
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        s*=a[i];
        s%=19260817;
    }
    cout<<s;
}
