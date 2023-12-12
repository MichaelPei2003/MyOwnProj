#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    long long m,n,t,i,j;
    cin>>m>>n;
    long long a[m]={0};
    for(i=1;i<=n;i++)
    {
        cin>>t;
        a[t-1]++;
    }
    long long top=0;
    t=0;
    for(i=0;i<m;i++)
    {
        if(a[i]>=n/2){t=i+1;}
    }
    if(t!=0){cout<<t;}
    else{cout<<"bad meeting";}
}
