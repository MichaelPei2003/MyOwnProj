#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    srand((unsigned int) time(NULL));
    int x,y,n;
    int a[100];
    for(int i=0;i<100;i++)
    {
        a[i]=100;
    }
    cout<<"请输入天数，退出请输入999:";
    cin>>n;
    if(x==999){exit(0);}
    for(int i=1;i<=n;i++)
    {

        x=rand()%100;
        y=rand()%100;
        a[x]+=1;
        a[y]-=1;
    }
    for(int i=1;i<100;i++)
    {
        printf("%5d",a[i]);
        if(i%10==0){printf("\n");}
    }
}
