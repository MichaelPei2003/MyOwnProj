#include <bits/stdc++.h>

using namespace std;

void chicken1()
{
    int rooster,hen,chick,i;
    i=0;
    for(rooster=0;rooster<=100;rooster++)
    {
        for(hen=0;hen<=100-rooster;hen++)
        {
            chick=100-rooster-hen;
            if(rooster*15+hen*9+chick==300)
            {
                i++;
                printf("\n��%d������������%dֻ��ĸ��%dֻ��С��%dֻ",i,rooster,hen,chick);
            }
        }
    }
}

void chicken2()
{
    int rooster,hen,chick;
    int i=0;
    for(rooster=0;rooster<=100/5;rooster++)
    {
        for(hen=0;hen<=(100-rooster*5)/3;hen++)
        {
            chick=3*(100-rooster*5-hen*3);
            if(rooster+hen+chick==100)
            {
                i++;
                printf("\n��%d������������%dֻ��ĸ��%dֻ��С��%dֻ",i,rooster,hen,chick);
            }
        }
    }
}

void triangle()
{
    int l;
    cout<<"�������ܳ������ֵ:";
    cin>>l;
    int a,b,c,i;
    i=0;
    for(a=1;a<=l;a++)
    {
        for(b=1;b<l-a&&b<=a;b++)
        {
            for(c=1;c<=l-a-b&&c<=b;c++)
            {
                if(pow(a,2)==(pow(b,2)+pow(c,2))){i++;cout<<a<<","<<b<<","<<c<<endl;}
            }
        }
    }
    cout<<"�ܳ���"<<l<<"���ڵ�ֱ����������Ϊ"<<i;
}

void book()
{
    int a,b,c,i,j,k,n,t;
    a=b=c=n=0;
    cout<<"���м�����ɽ�?"<<endl;
    cout<<"������һ����:";
    cin>>t;
    for(k=1;k<=t;k++)
    {
        a=k;
        for(i=1;i<=t;i++)
        {
            b=i;
            for(j=1;j<=t;j++)
            {
                c=j;
                if(a!=b&&b!=c&&a!=c){cout<<"      A�õ���"<<a<<"����"<<"  B�õ���"<<b<<"����"<<"  C�õ���"<<c<<"����"<<endl;n++;}
            }
        }
    }
    cout<<"����"<<n<<"�ֿ���";
}

int menu()
{
    cout<<"\t ________________________________"<<endl;
    cout<<"\t|               �˵�             |"<<endl;
    cout<<"\t| 1.�ټ���Ǯ����1(������ѭ��)    |"<<endl;
    cout<<"\t| 2.�ټ���Ǯ����2(�۸�ѭ��)      |"<<endl;
    cout<<"\t| 3.ֱ�������θ���(�߳�1000����) |"<<endl;
    cout<<"\t| 4.n������������              |"<<endl;
    cout<<"\t|                                |"<<endl;
    cout<<"\t|                                |"<<endl;
    cout<<"\t| 0.�˳�                         |"<<endl;
    cout<<"\t|________________________________|"<<endl;
    cout<<"����������ѡ��";
    int choice;
    for(;;)
    {
        scanf("%d",&choice);
        switch(choice)
        {
            case 0:exit(0);
            case 1:chicken1();break;
            case 2:chicken2();break;
            case 3:triangle();break;
            case 4:book();break;
            default:cout<<"��Ч����,����������:";continue;
        }
        cout<<endl;
        menu();
    }
}

int main(void)
{
    menu();
}
