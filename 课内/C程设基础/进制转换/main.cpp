#include <iostream>
#include <cstdio>

using namespace std;

int main(void)
{
    cout<<"\n\t============�������������============="<<endl;
    int i;
    while (1)
    {
        int a=0;
        cout<<"������һ����:";
        cin>>a;
        cout<<"�����������"<<a<<endl;
        cout<<"����"<<a<<"��16����ֵΪ:"<<hex<<a<<endl;
        cout<<"����"<<dec<<a<<"��8����ֵΪ:"<<oct<<a<<endl;
        cout<<"\t=========���ǰ����0��0x========="<<endl;
        printf("����%d��16����ֵΪ:%#x\n",a,a);
        printf("����%d��8����ֵΪ;%#o\n",a,a);
        cout<<"\t=========�����5λ�Ҷ���========="<<endl;
        printf("����%d��16����ֵΪ:%5d\n",a,a);
        cout<<"\t=========�����5λ�Ҷ��벹��========"<<endl;
        printf("����%d��16����ֵΪ%05d\n",a,a);
    }
}
