#include <stdio.h>

int main(void)
{
    int a,b,c,s;
    c=1;s=0;
    scanf("%d%d",&a,&b);
    while(a<=b)
    {
        if(c%5==0)
        {
            if((a+1)>b)
            {
                printf("%5d",a);
                s=s+a;
                a=a+1;
            }
            else
            {   printf("%5d\n",a);
               s=s+a;
               a++;
               c++;
            }
        }
        else
        {
           printf("%5d",a);
           s=s+a;
           a++;
           c++;
        }
    }
    printf("\nSum = %d",s);
}
