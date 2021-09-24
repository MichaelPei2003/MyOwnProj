#include <stdio.h>
#include <math.h>

int main(void)
{
    double x,a;
    scanf("%lf",&x);
    a=x;
    if(x>=0)
    {
        x=sqrt(x);
    }
    else
    {
        x=pow(x+1,2)+2*x+1/x;
    }
    printf("f(%.2lf) = %.2lf",a,x);
}
