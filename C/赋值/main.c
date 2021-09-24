#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    short x,y;
    x=3;
    y=pow(x,2);
    printf("%d = %d * %d\n",y,x,x);
    printf("%d * %d = %d",x,x,y);
}
