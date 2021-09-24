#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a,b;
    scanf("%d%d",&a,&b);
    if(a==0&&b==0)
    {
        exit(0);
    }
    else
    {
        printf("%d",a+b);
    }
}
