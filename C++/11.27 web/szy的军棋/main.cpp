#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    long long n,d,i,j;
    scanf("%lld %lld",&n,&d);
    long long pi[n+1]={0},s=0;
    for(i=0;i<n;i++)
    {
        scanf("%lld",&pi[i]);
    }
    sort(pi,pi+n);
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(pi[j]-pi[i]<=d)
            {
                s++;
            }
            else{break;}
        }
    }
    printf("%d",s);
}
