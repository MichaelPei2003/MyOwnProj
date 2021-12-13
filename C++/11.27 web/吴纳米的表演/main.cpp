#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n,i;
    long long s=0;
    cin>>n;
    int jq[n+1]= {0},num[n+1]= {0};
    for(i=0; i<n; i++)
    {
        cin>>jq[i];
    }
    for(i=0; i<n; i++)
    {
        cin>>num[i];
    }
    sort(jq,jq+n);
    sort(num,num+n);
    for(i=0; i<n; i++)
    {
        s+=jq[i]*num[i];
    }
    cout<<s;
}
