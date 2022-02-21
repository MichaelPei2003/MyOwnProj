#include <bits/stdc++.h>

//指针数组：是一个由指针元素构成的数组 int *p[n]
//数组指针：int (*p)[10]//定义一个指针指向一个有10个元素的数组

using namespace std;

int main(void)
{
    int x[3][4],(*p)[4],i,j,s;
    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
        {
            scanf("%d",&x[i][j]);
        }
    }
    p=x;
    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
        {
            s+=*(*(p+i)+j);
        }
    }
    cout<<s;
}
