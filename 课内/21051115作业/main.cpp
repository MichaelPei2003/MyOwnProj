#include <iostream>

using namespace std;

void zhuanhuan()
{

    char a[101];
    int i=0,count;
    printf("�����벻����100�ַ���");
    while(a[i]=getchar(),a[i]!='\n')
    {
        i++;
    }
    a[i]='\0';
    printf("������ַ���Ϊ��%s\n",a);
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
    printf("��ȥ��16��������Ϊ��%s\n",s16);
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

}

void zheban()
{

    int N;
    cout<<"�����������С��";
    cin>>N;
    int a[N];
    for(int i=0; i<=N; i++)
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
        cout<<"Ҫ���ҵ�ֵ"<<x<<"λ��a["<<mid<<"]"<<endl;
    }
    else
    {
        cout<<"û���ҵ�"<<x;
    }
    if(x==888)
    {
        exit(0);
    }
}


void maopao()
{
    int i,j,n,m;
    cin>>n;
    int a[n];
    for(i=0; i<n-1; i++)
    {
        a[i]=rand()%1000;
    }
    printf("��������ǰ��״̬Ϊ��\n");
    for(i=0; i<n; i++)
    {
        printf("%5d",a[i]);
        if((i+1)%10==0)
        {
            cout<<endl;
        }
    }
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
    cout<<"������״̬Ϊ��"<<endl;
    for(i=0; i<n; i++)
    {
        printf("%5d",a[i]);
        if((i+1)%10==0)
        {
            cout<<endl;
        }
    }
}

void xuanze()
{

}

void juzhen()
{

}

void mmdd()
{

}

void  menu()
{
    int a=0;
    printf(" ______________________menu______________________\n");
    printf("| 1.�۰����              2.ð������             |\n");
    printf("| 3.ѡ������              4.�������             |\n");
    printf("| 5.ĳ��ĳ��              6.�ַ�ת��             |\n");
    printf("|________________________________________________|\n");
    printf("������ѡ��س�:");
    scanf("%d",&a);
    if(a==1)
    {
        zheban();
    }
    else if(a==2)
    {
        maopao());
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
        printf("��Ч����!");
        menu();
    }
}

