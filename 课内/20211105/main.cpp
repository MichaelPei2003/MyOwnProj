#include <bits/stdc++.h>

using namespace std;

/*int func1(void)
{
    int N;
    cout<<"�����������С��";
    cin>>N;
    int a[N];
    for(int i=0;i<=N;i++)
    {
        a[i]=i*2;
    }
    int x;
    printf("������Ҫ���ҵ�ֵ,����888���˳���");
    scanf("%d",&x);
    int top,bot,mid;
    top=0;
    bot=N-1;
    while(top<=bot)
    {
        mid=(top+bot)/2;
        if(x==a[mid]){break;}
        else
        {
            if(x>a[mid]){top=mid+1;}
            else{bot=mid-1;}
        }
    }
    if(x==a[mid]){cout<<"Ҫ���ҵ�ֵ"<<x<<"λ��a["<<mid<<"]"<<endl;}
    else{cout<<"û���ҵ�"<<x;}
    if(x==888){exit(0);}
}
*/
int func1(void)
{
    int i,j,n,m;
    cin>>n;
    int a[n];
    for(i=0;i<n-1;i++)
    {
        a[i]=rand()%1000;
    }
    printf("��������ǰ��״̬Ϊ��\n");
    for(i=0;i<n;i++)
    {
        printf("%5d",a[i]);
        if((i+1)%10==0){cout<<endl;}
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                m=a[j];
                a[j]=a[j+1];
                a[j+1]=m;
            }
        }
    }
    cout<<"������״̬Ϊ��"<<endl;
    for(i=0;i<n;i++)
    {
        printf("%5d",a[i]);
        if((i+1)%10==0){cout<<endl;}
    }
}

int main(void)
{
    srand((unsigned int) time(NULL));
    while(1)
    {
        func1();
    }
}
