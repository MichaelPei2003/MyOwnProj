#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand((unsigned int) time(NULL));
    menu();
}

void  menu()
{
    int a=0;
    printf(" ______________________menu______________________\n");
    printf("| 1.�ӷ�                  2.����                 |\n");
    printf("| 3.�˷�                  4.����                 |\n");
    printf("| 5.�������              6.�˳�                 |\n");
    printf("|________________________________________________|\n");
    printf("������ѡ��س�:");
    scanf("%d",&a);
    if(a==1){jiafa();}
    else if(a==2){jianfa();}
    else if(a==3){chengfa();}
    else if(a==4){chufa();}
    else if(a==5){hunhe();}
    else if(a==6){exit(0);}
    else
    {
        printf("��Ч����!");
        menu();
    }
}

void jiafa()
{
    int x,y,z,i;
    i=0;
    printf("______________________�ӷ�______________________\n");
    printf("___________________����888�˳�__________________\n");
    for(;;)
    {
        for(;;)
        {
            x=rand()%20;
            y=rand()%20;
            if(x+y<=20)
            {
                break;
            }
        }
        for(;;)
        {
            printf("%d+%d=",x,y);
            scanf("%d",&z);
            if(z==(x+y))
            {
                i++;
                printf("��ϲ����������˵�%d��\n",i);
                break;
            }
            else if(z!=888){i=0;continue;}
            else{break;}
        }
        if(z==888){printf("�������˵�\n");break;}
    }
    menu();
}

void jianfa()
{
    int x,y,z,i;
    i=0;
    printf("______________________����______________________\n");
    printf("___________________����888�˳�__________________\n");
    for(;;)
    {
        for(;;)
        {
            x=rand()%20;
            y=rand()%20;
            if(x-y>=0)
            {
                break;
            }
        }
        for(;;)
        {
            printf("%d-%d=",x,y);
            scanf("%d",&z);
            if(z==(x-y))
            {
                i++;
                printf("��ϲ����������˵�%d��\n",i);
                break;
            }
            else if(z!=888){i=0;continue;}
            else{break;}
        }
        if(z==888){printf("�������˵�\n");break;}
    }
    menu();
}

void chengfa()
{
    int x,y,z,i;
    i=0;
    printf("______________________�˷�______________________\n");
    printf("___________________����888�˳�__________________\n");
    for(;;)
    {
        for(;;)
        {
            x=rand()%20;
            y=rand()%20;
            if(x*y<=20&&x*y!=0)
            {
                break;
            }
        }
        for(;;)
        {
            printf("%d*%d=",x,y);
            scanf("%d",&z);
            if(z==(x*y))
            {
                i++;
                printf("��ϲ����������˵�%d��\n",i);
                break;
            }
            else if(z!=888){i=0;continue;}
            else{break;}
        }
        if(z==888){printf("�������˵�\n");break;}
    }
    menu();
}

void chufa()
{
    int x,y,z,i;
    i=0;
    printf("______________________����______________________\n");
    printf("___________________����888�˳�__________________\n");
    for(;;)
    {
        for(;;)
        {
            x=rand()%20;
            y=rand()%20;
            if(x*y<=20&&x*y!=0)
            {
                break;
            }
        }
        for(;;)
        {
            z=x*y;
            printf("%d/%d=",z,y);
            scanf("%d",&x);
            if(x==(z/y))
            {
                i++;
                printf("��ϲ����������˵�%d��\n",i);
                break;
            }
            else if(x!=888){i=0;continue;}
            else{break;}
        }
        if(x==888){printf("�������˵�\n");break;}
    }
    menu();
}

void hunhe()
{
    int x,y,z,i,n;
    i=0;
    printf("____________________��ϼ���____________________\n");
    printf("___________________����888�˳�__________________\n");
    for(;;)
    {
        n=rand()%3;
        switch (n)
        {
        case 0:
            for(;;)
            {
                x=rand()%20;
                y=rand()%20;
                if(x+y<=20)
                {
                    break;
                }
            }
            for(;;)
            {
                printf("%d+%d=",x,y);
                scanf("%d",&z);
                if(z==(x+y))
                {
                    i++;
                    printf("��ϲ����������˵�%d��\n",i);
                    break;
                }
                else if(z!=888){i=0;continue;}
                else{break;}
            }
        case 1:
            for(;;)
            {
                x=rand()%20;
                y=rand()%20;
                if(x-y>=0)
                {
                    break;
                }
            }
            for(;;)
            {
                printf("%d-%d=",x,y);
                scanf("%d",&z);
                if(z==(x-y))
                {
                    i++;
                    printf("��ϲ����������˵�%d��\n",i);
                    break;
                }
                else if(z!=888){i=0;continue;}
                else{break;}
            }
        case 2:
            for(;;)
            {
                x=rand()%20;
                y=rand()%20;
                if(x*y<=20&&x*y!=0)
                {
                    break;
                }
            }
            for(;;)
            {
                printf("%d*%d=",x,y);
                scanf("%d",&z);
                if(z==(x*y))
                {
                    i++;
                    printf("��ϲ����������˵�%d��\n",i);
                    break;
                }
                else if(z!=888){i=0;continue;}
                else{break;}
            }
        case 3:
            for(;;)
            {
                x=rand()%20;
                y=rand()%20;
                if(x*y<=20&&x*y!=0)
                {
                    break;
                }
            }
            for(;;)
            {
                z=x*y;
                printf("%d/%d=",z,y);
                scanf("%d",&x);
                if(x==(z/y))
                {
                    i++;
                    printf("��ϲ����������˵�%d��\n",i);
                    break;
                }
                else if(x!=888){i=0;continue;}
                else{break;}
            }
        }
        if(x==888){printf("�������˵�");break;}
    }
    menu();
}
