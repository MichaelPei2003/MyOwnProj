#include <stdio.h>
#include <math.h>

int main(void)
{
    int a,b,c,d,e,i;
    i=0;
    scanf("%d",&e);
    if(e==0){printf("ling");exit(0);}
    if(e<0)
    {
        printf("fu ");
        e=-e;
    }
    c=e;//储存e保持e的值不变
    for(;c>0;)//求输入数字的位数
    {
        c/=10;
        i++;
    }
    for(;e!=0;)
    {
        b=pow(10,i-1);
        a=e/b;//从高位向低位拆数
        switch(a)
        {
           case 1:printf("yi");break;
           case 2:printf("er");break;
           case 3:printf("san");break;
           case 4:printf("si");break;
           case 5:printf("wu");break;
           case 6:printf("liu");break;
           case 7:printf("qi");break;
           case 8:printf("ba");break;
           case 9:printf("jiu");break;
           case 0:printf("ling");break;
       }
       i--;//减一位
       if(e-a*b==0)//防止诸如1000等数出错
       {
           while(i!=0)
           {
               printf(" ling");
               i--;
           }
       }
       if(i!=0)
       {
           printf(" ");
       }
       e=e-a*b;//去掉已输出的数位
    }
}
