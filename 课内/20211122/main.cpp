#include <bits/stdc++.h>

//ָ�����飺��һ����ָ��Ԫ�ع��ɵ����� int *p[n]
//����ָ�룺int (*p)[10]//����һ��ָ��ָ��һ����10��Ԫ�ص�����

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
