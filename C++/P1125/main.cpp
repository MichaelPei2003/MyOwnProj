#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main(void)
{
    char a[110]={0};
    int ans[26]={0};
    int l,maxn,minn,delta;
    scanf("%s",a);
    l=strlen(a);
    for (int i=0;i<l;i++)
    {
        ans[a[i]-'a']++;
        minn=10000;
        maxn=0;
    }
    for(int i=0;i<26;i++)
    {
        if(ans[i]!=0&&ans[i]<minn)
        {
            minn=ans[i];
        }
        if(ans[i]>maxn)
        {
            maxn=ans[i];
        }
    }
    delta=maxn-minn;
    if(delta==0||delta==1)
    {
        cout<<"No Answer"<<endl<<0;
        exit(0);
    }
    else
    {
        for(int i=2;i*i<=delta;i++)
        {
            if (delta==i)
            {
                cout<<"No Answer"<<endl<<0;
                exit(0);
            }
        }
        cout<<"Lucky Word"<<endl<<delta;
    }
}
