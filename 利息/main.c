#include <stdio.h>
#include <math.h>

int main(void)
{
    double i,m,r,y;
    scanf("%lf%lf%lf",&m,&y,&r);
    i=m*pow(1+r,y)-m;
    printf("interest = %.2lf",i);
}
