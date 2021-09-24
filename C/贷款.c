#include <stdio.h>
#include <math.h>

int main()
{
    double d,p,r,m;
    scanf("%lf%lf%lf",&d,&p,&r);
    m=log10(p/(p-d*r))/(log10(1+r));
    printf("%.1f",m);
    return 0;
}
