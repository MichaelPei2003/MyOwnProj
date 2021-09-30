#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    long long x,y,a,b;
    a=b=0;
    cin>>x>>y;
    for(int i=0;i<x;++i)
    {
        for(int j=0;j<y;j++)
        {
            if(i==j){a+=(x-i)*(y-j);}
            else{b+=(x-i)*(y-j);}
        }
    }
    cout<<a<<" "<<b;
}
