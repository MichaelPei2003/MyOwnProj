#include <stdio.h>

int main(void)
{
    int a,b,c,i;
    scanf("%d",&a);
    b=(a-a%10)/100;
    c=(a%100)/10;
    i=a%10;
    printf("%d,%d,%d",b,c,i);
}
