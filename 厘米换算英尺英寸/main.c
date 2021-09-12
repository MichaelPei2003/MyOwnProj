#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    double c,f,i,d;
    scanf("%lf",&c);
    c=c/100/0.3048;
    d=floor(c);
    f=d;
    i=(c-d)*12;
    i=floor(i);
    printf("%.lf %.lf",f,i);
}
