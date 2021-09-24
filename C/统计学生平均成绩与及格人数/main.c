#include <stdio.h>

int main(void)
{
    double a,b;//a=all,b=avrg
    int i,c,d,n;//c=num of stu d=input n=passed
    i=0;c=0;n=0;
    scanf("%d",&c);
    if(c==0)
    {
        b=0;n=0;
    }
    else
    {
     for(i=1;i<=c;i++)
    {
        scanf("%d",&d);
        a=a+d;
        if(d>=60)
        {
            n=n+1;
        }
    }
    b=a/c;
    }
    printf("average = %.1lf\ncount = %d",b,n);
}
