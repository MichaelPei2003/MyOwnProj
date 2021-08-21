#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a,b,c,d;
    double e;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    e=(double)(a+b+c+d)/4;
    printf("Sum = %d; Average = %.1lf",a+b+c+d,e);
}
