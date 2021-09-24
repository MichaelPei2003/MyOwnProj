#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int s,v,h,m,h1,m1;
    scanf("%d%d",&s,&v);
    m1=s/v+10;
    if(s%v!=0)
    {
        m1+=1;
    }
    h=8;
    m=0-m1;
    while(m<0)
    {
        h-=1;
        m+=60;
    }
    if(h<0)
    {
        h+=24;
    }
    printf("%02d:%02d",h,m);
}
