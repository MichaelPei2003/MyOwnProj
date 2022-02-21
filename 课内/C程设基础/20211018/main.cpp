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
                printf("\n第%d个方案：公鸡%d只，母鸡%d只，小鸡%d只",i,rooster,hen,chick);
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
                printf("\n第%d个方案：公鸡%d只，母鸡%d只，小鸡%d只",i,rooster,hen,chick);
            }
        }
    }
}

void triangle()
{
    int l;
    cout<<"请输入周长的最大值:";
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
    cout<<"周长在"<<l<<"以内的直角三角形数为"<<i;
}

void book()
{
    int a,b,c,i,j,k,n,t;
    a=b=c=n=0;
    cout<<"共有几本书可借?"<<endl;
    cout<<"请输入一个数:";
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
                if(a!=b&&b!=c&&a!=c){cout<<"      A得到第"<<a<<"本书"<<"  B得到第"<<b<<"本书"<<"  C得到第"<<c<<"本书"<<endl;n++;}
            }
        }
    }
    cout<<"共有"<<n<<"种可能";
}

int menu()
{
    cout<<"\t ________________________________"<<endl;
    cout<<"\t|               菜单             |"<<endl;
    cout<<"\t| 1.百鸡百钱方法1(鸡个数循环)    |"<<endl;
    cout<<"\t| 2.百鸡百钱方法2(价格循环)      |"<<endl;
    cout<<"\t| 3.直角三角形个数(边长1000以内) |"<<endl;
    cout<<"\t| 4.n本书借给三个人              |"<<endl;
    cout<<"\t|                                |"<<endl;
    cout<<"\t|                                |"<<endl;
    cout<<"\t| 0.退出                         |"<<endl;
    cout<<"\t|________________________________|"<<endl;
    cout<<"请输入您的选择：";
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
            default:cout<<"无效输入,请重新输入:";continue;
        }
        cout<<endl;
        menu();
    }
}

int main(void)
{
    menu();
}
