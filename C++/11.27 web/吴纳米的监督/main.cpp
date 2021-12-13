#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n,m,d,t;
    t=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d %d",&m,&d);
        if(m%2!=0&&d%2==0)
        {
            t+=d;
        }
    }
    printf("%d",t);
}
