#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

/*int main(void)
{
    int maxInt=pow(2,32)-1;
    int minInt=-pow(2,32);
    cout<<"整数int型的字节数是:"<<sizeof(int)<<endl;
    cout<<"最大的整数是:"<<maxInt<<endl;
    cout<<"最小的整数是:"<<minInt<<endl;
    cout<<"最大的整数+1是:"<<maxInt+1<<endl;
    cout<<"最小的整数-1是:"<<minInt-1<<endl<<endl;
    cout<<"字符char的字节数是:"<<sizeof(char)<<endl;
    cout<<"单精度浮点数float的字节数是:"<<sizeof(float)<<endl;
    cout<<"双精度浮点数double的字节数是:"<<sizeof(double);
}
*/int main(void)
{
    int x;
    cout<<"输入:";
    cin>>x;
    if(x==1) a();
    else b();
int a(void)
{
    int maxInt=pow(2,32)-1;
    int minInt=-pow(2,32);
    printf("整数int的字节数是:%d",sizeof(int));
    printf("\n最大的整数是:%d",maxInt);
    printf("\n最小的整数是:%d",minInt);
    printf("\n最大的整数+1是:%d",maxInt+1);
    printf("\n最小的整数-1是:%d",minInt-1);
    printf("\n\n字符char的字节数是:%d",sizeof(char));
    printf("\n单精度浮点数float的字节数是:%d",sizeof(float));
    printf("\n双精度浮点数float的字节数是:%d",sizeof(float));
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
