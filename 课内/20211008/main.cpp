#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

/*int main(void)
{
    int maxInt=pow(2,32)-1;
    int minInt=-pow(2,32);
    cout<<"����int�͵��ֽ�����:"<<sizeof(int)<<endl;
    cout<<"����������:"<<maxInt<<endl;
    cout<<"��С��������:"<<minInt<<endl;
    cout<<"��������+1��:"<<maxInt+1<<endl;
    cout<<"��С������-1��:"<<minInt-1<<endl<<endl;
    cout<<"�ַ�char���ֽ�����:"<<sizeof(char)<<endl;
    cout<<"�����ȸ�����float���ֽ�����:"<<sizeof(float)<<endl;
    cout<<"˫���ȸ�����double���ֽ�����:"<<sizeof(double);
}
*/int main(void)
{
    int x;
    cout<<"����:";
    cin>>x;
    if(x==1) a();
    else b();
int a(void)
{
    int maxInt=pow(2,32)-1;
    int minInt=-pow(2,32);
    printf("����int���ֽ�����:%d",sizeof(int));
    printf("\n����������:%d",maxInt);
    printf("\n��С��������:%d",minInt);
    printf("\n��������+1��:%d",maxInt+1);
    printf("\n��С������-1��:%d",minInt-1);
    printf("\n\n�ַ�char���ֽ�����:%d",sizeof(char));
    printf("\n�����ȸ�����float���ֽ�����:%d",sizeof(float));
    printf("\n˫���ȸ�����float���ֽ�����:%d",sizeof(float));
}
int b(void)
{
    int a=0;
    while(a!=1)
    {
        a+=0.1;
        cout<<setw(8)<<setfill(0)<<a<<endl;
        system(pause);
    }
}
