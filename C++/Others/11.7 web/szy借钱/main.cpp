#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    long long q,z,n;
    cin>>q>>z>>n;
    long long a[n+10]={0},top=0,out=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]>=0)
        {
            q+=a[i];
            top=max(top,a[i]);
        }
        else if(q>=-a[i])
        {
            q+=a[i];
            out-=a[i];
        }
    }
    cout<<q<<endl;
    if(q>=z)
    {
        cout<<top<<endl<<"thank you!";
    }
    else
    {
        cout<<out<<endl<<"oh no!";
    }
}
