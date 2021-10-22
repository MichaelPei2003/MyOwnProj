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
    printf("| 1.加法                  2.减法                 |\n");
    printf("| 3.乘法                  4.除法                 |\n");
    printf("| 5.混合运算              6.退出                 |\n");
    printf("|________________________________________________|\n");
    printf("请输入选项并回车:");
    scanf("%d",&a);
    if(a==1){jiafa();}
    else if(a==2){jianfa();}
    else if(a==3){chengfa();}
    else if(a==4){chufa();}
    else if(a==5){hunhe();}
    else if(a==6){exit(0);}
    else
    {
        printf("无效输入!");
        menu();
    }
}

void jiafa()
{
    int x,y,z,i;
    i=0;
    printf("______________________加法______________________\n");
    printf("___________________输入888退出__________________\n");
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
                printf("恭喜你连续答对了第%d题\n",i);
                break;
            }
            else if(z!=888){i=0;continue;}
            else{break;}
        }
        if(z==888){printf("返回主菜单\n");break;}
    }
    menu();
}

void jianfa()
{
    int x,y,z,i;
    i=0;
    printf("______________________减法______________________\n");
    printf("___________________输入888退出__________________\n");
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
                printf("恭喜你连续答对了第%d题\n",i);
                break;
            }
            else if(z!=888){i=0;continue;}
            else{break;}
        }
        if(z==888){printf("返回主菜单\n");break;}
    }
    menu();
}

void chengfa()
{
    int x,y,z,i;
    i=0;
    printf("______________________乘法______________________\n");
    printf("___________________输入888退出__________________\n");
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
                printf("恭喜你连续答对了第%d题\n",i);
                break;
            }
            else if(z!=888){i=0;continue;}
            else{break;}
        }
        if(z==888){printf("返回主菜单\n");break;}
    }
    menu();
}

void chufa()
{
    int x,y,z,i;
    i=0;
    printf("______________________除法______________________\n");
    printf("___________________输入888退出__________________\n");
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
                printf("恭喜你连续答对了第%d题\n",i);
                break;
            }
            else if(x!=888){i=0;continue;}
            else{break;}
        }
        if(x==888){printf("返回主菜单\n");break;}
    }
    menu();
}

void hunhe()
{
    int x,y,z,i,n;
    i=0;
    printf("____________________混合计算____________________\n");
    printf("___________________输入888退出__________________\n");
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
                    printf("恭喜你连续答对了第%d题\n",i);
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
                    printf("恭喜你连续答对了第%d题\n",i);
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
                    printf("恭喜你连续答对了第%d题\n",i);
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
                    printf("恭喜你连续答对了第%d题\n",i);
                    break;
                }
                else if(x!=888){i=0;continue;}
                else{break;}
            }
        }
        if(x==888){printf("返回主菜单");break;}
    }
    menu();
}
