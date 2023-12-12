#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    long long a,b,s=0;
    cin>>a>>b;
    for(int i=a;i<=b;i++)
    {
        int n=i;
        while(n!=0)
        {
            if(n%10==2){s+=1;}
            n/=10;
        }
    }
    cout<<s;
}
