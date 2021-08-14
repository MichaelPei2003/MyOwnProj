#include <stdio.h>
#include<math.h>

int main()
{
    double r,n,p;
    scanf("%lf%lf",&r,&n);
    p=pow(1+r,n);
    printf("p=%6.4f",p);
    return 0;
}
