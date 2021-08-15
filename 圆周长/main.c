#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926
int main()
{
    double r,c,s;
    scanf("%lf",&r);
    c=2*PI*r;
    s=PI*pow(r,2);
    printf("c=%.3lf,s=%.3lf",c,s);
    return 0;
}
