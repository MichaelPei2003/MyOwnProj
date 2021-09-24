#include <stdio.h>

int main(void)
{
    int n,a,u,b,z;
    a=0;b=0;u=0;z=0;
    scanf("%d",&n);
    if(n%2==0&&n>4&&n<=12){a=1;}
    if("n%2==0")
        u=1;
    else if(n>4&&n<=12)
        u=1;
    if(n%2==0^n>4&&n<=12)
        b=1;
    if(n%2!=0)
        if(n<=4||n>12)
            z=1;
    printf("%d %d %d %d",a,u,b,z);
}
