#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

using namespace std;

void zhuanhuan()
{
    fflush(stdin);
    char a[101];
    int i=0;
    printf("请输入不超过100字符：");
    while(a[i]=getchar(),a[i]!='\n')
    {
        i++;
    }
    a[i]='\0';
    printf("输入的字符串为：%s\n",a);
    char s16[i];
    int k=0;
    for(int j=0; a[j]!='\0'; j++)
    {
        if((a[j]>='0'&&a[j]<='9')||(a[j]>='a'&&a[j]<='f')||(a[j]>='A'&&a[j]<='F'))
        {
            s16[k]=a[j];
            k++;
        }
    }
    s16[k]='\0';
    printf("滤去非16进制数后为：%s\n",s16);
    int num=0,t=0;
    for(i=0; s16[i]!='\0'; i++)
    {
        if(s16[i]<='9')
        {
            num=num*16+s16[i]-'0';
        }
        else if(s16[i]>='a'&&s16[i]<='f')
        {
            num=num*16+s16[i]-'a'+10;
        }
        else
        {
            num=num*16+s16[i]-'A'+10;
        }
    }
    printf("%d",num);
    cout<<endl;
}

void zheban()
{
    fflush(stdin);
    int N;
    cout<<"请输入数组大小：";
    cin>>N;
    int a[N];
    for(int i=0; i<=N; i++)
    {
        a[i]=i*2;
    }
    int x;
    printf("请输入要查找的值,输入888以退出：");
    scanf("%d",&x);
    int top,bot,mid;
    top=0;
    bot=N-1;
    while(top<=bot)
    {
        mid=(top+bot)/2;
        if(x==a[mid])
        {
            break;
        }
        else
        {
            if(x>a[mid])
            {
                top=mid+1;
            }
            else
            {
                bot=mid-1;
            }
        }
    }
    if(x==a[mid])
    {
        cout<<"要查找的值"<<x<<"位于a["<<mid<<"]"<<endl;
    }
    else
    {
        cout<<"没有找到"<<x;
    }
    if(x==888)
    {
        exit(0);
    }
}


void maopao()
{
    fflush(stdin);
    int i,j,n,m;
    cout<<"请输入数组大小:";
    cin>>n;
    int a[n];
    for(i=0; i<n-1; i++)
    {
        a[i]=rand()%1000;
    }
    printf("数列排序前的状态为：\n");
    for(i=0; i<n; i++)
    {
        printf("%5d",a[i]);
        if((i+1)%10==0)
        {
            cout<<endl;
        }
    }
    cout<<endl;
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-1-i; j++)
        {
            if(a[j]>a[j+1])
            {
                m=a[j];
                a[j]=a[j+1];
                a[j+1]=m;
            }
        }
    }
    cout<<"排序后的状态为："<<endl;
    for(i=0; i<n; i++)
    {
        printf("%5d",a[i]);
        if((i+1)%10==0)
        {
            cout<<endl;
        }
    }
    cout<<endl;
}

void xuanze()
{
    fflush(stdin);
    printf("从小到大的选择排序\n请输入数字个数:");
    int m;
    scanf("%d", &m);
    printf("\n请输入%d个一百以内的数字：",m);
    int a[100];
    for(int i; i<m; i++)
    {
        scanf("%d",&a[i]);
    }
    int t;
    int pos;
    for(int i=0; i<m; i++)
    {
        pos=i;
        for(int j=i; j<m; j++)
        {
            if(a[j]<a[pos])
            {
                pos=j;
            }
        }
        t=a[i];
        a[i]=a[pos];
        a[pos]=t;
    }
    printf("\n升序排序：");
    for(int i=0; i<m; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

void juzhen()
{
    int n;
    printf("请输入矩阵的阶数：");
    scanf("%d",&n);
    printf("请输入一个%d阶矩阵:\n",n);
    int a[n+1][n+1];
    int b[n+1][n+1];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            scanf("%d",&a[i][j]);
            b[i][j]=a[i][j];
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            b[j][n-i+1]=a[i][j];
        }
    }
    printf("\n顺时针90度：\n");
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            b[n-i+1][n-j+1]=a[i][j];
        }
    }
    printf("\n顺时针180度：\n");
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
}

void mmdd()
{
    fflush(stdin);
    printf("\n请输入要查找的日期，格式为x月x日：");
    int x,y;
    scanf("%d月%d日", &x, &y);
    int a[366];
    a[1] = 5;
    for(int i=2; i<365; i++)
    {
        a[i]=a[i-1]+1;
        if(a[i]==8){a[i]=1;}
    }
    int sum=0;
    //printf("%d", a[365]) ;
    for(int i=1; i<x; i++)
    {
        if(i==1||i==3||i==5||i==7||i==8||i==10||i==12){sum += 31;}
        else if(i==2) {sum+=28;}
        else {sum+=30;}
    }
    sum=sum+y-1;
    printf("\n这个日子是星期%d\n", a[sum+1]);
}

void  menu()
{
    int a=0;
    printf(" ______________________menu______________________\n");
    printf("| 1.折半查找              2.冒泡排序             |\n");
    printf("| 3.选择排序              4.矩阵操作             |\n");
    printf("| 5.某年某日              6.字符转换             |\n");
    printf("|________________________________________________|\n");
    printf("请输入选项并回车:");
    scanf("%d",&a);
    if(a==1)
    {
        zheban();
    }
    else if(a==2)
    {
        maopao();
    }
    else if(a==3)
    {
        xuanze();
    }
    else if(a==4)
    {
        juzhen();
    }
    else if(a==5)
    {
        mmdd();
    }
    else if(a==6)
    {
        zhuanhuan();
    }
    else
    {
        printf("无效输入!");
        menu();
    }
    menu();
}

int main()
{
    menu();
}
