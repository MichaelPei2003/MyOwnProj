#include <iostream>
#include <cstdio>

using namespace std;

int main(void)
{
    cout<<"\n\t============各进制数的输出============="<<endl;
    int i;
    while (1)
    {
        int a=0;
        cout<<"请输入一个数:";
        cin>>a;
        cout<<"你输入的数是"<<a<<endl;
        cout<<"整数"<<a<<"的16进制值为:"<<hex<<a<<endl;
        cout<<"整数"<<dec<<a<<"的8进制值为:"<<oct<<a<<endl;
        cout<<"\t=========输出前导的0和0x========="<<endl;
        printf("整数%d的16进制值为:%#x\n",a,a);
        printf("整数%d的8进制值为;%#o\n",a,a);
        cout<<"\t=========输出数5位右对齐========="<<endl;
        printf("整数%d的16进制值为:%5d\n",a,a);
        cout<<"\t=========输出数5位右对齐补零========"<<endl;
        printf("整数%d的16进制值为%05d\n",a,a);
    }
}
