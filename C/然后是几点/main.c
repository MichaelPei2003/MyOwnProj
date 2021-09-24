#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a,b,h,m,h2,m2;
    scanf("%d%d",&a,&b);
    h=a/100;
    m=a-h*100;
    if(b>0)
    {
        h2=b/60;
        m2=b-h2*60;
        h=h+h2;
        m=m+m2;
        if(m>=60)
        {
            m=m-60;
            h=h+1;
        }
    }
    else
    {
        b=-b;
        h2=b/60;
        m2=b-h2*60;
        h=h-h2;
        m=m-m2;
        if(m<0)
        {
            h=h-1;
            m=m+60;
        }
    }
    a=h*100+m;
    if(a<100)
    {
        printf("%03d",a);
    }
    else
    {
        printf("%d",a);
    }
}
