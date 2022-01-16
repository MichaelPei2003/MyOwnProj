#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n,i,j,k=2;
    cin>>n;
    if(n%2==0)
        exit(0);
    int a[n][n],r,c;
    memset(a,0,sizeof(a));
    a[0][(n-1)/2]=1;
    r=0;
    c=(n-1)/2;
    for(; k<=n*n; k++)
    {
        if(r==0&&c!=n-1)
        {
            r=n-1;
            c+=1;
        }
        else if(r!=0&&c==n-1)
        {
            r-=1;
            c=0;
        }
        else if(r==0&&c==n-1)
        {
            r+=1;
        }
        else
        {

            if(a[r-1][c+1]==0)
            {
                r-=1;
                c+=1;
            }
            else
            {
                r+=1;
            }
        }
        a[r][c]=k;
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            cout<<a[i][j]<<" ";
            if(j==n-1)
            {
                cout<<endl;
            }
        }
    }
}
