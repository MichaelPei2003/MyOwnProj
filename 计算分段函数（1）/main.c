#include <stdio.h>

int main(void)
{
    double x,y;
    scanf("%lf",&x);
    if (x==0){y=0;}
    else{y=1/x;}
    printf("f(%.1lf) = %.1lf",x,y);
}

