#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    unsigned k, n;
    scanf("%u", &n);   //输入数据为：69
    k=n%10*10+n/10;
    printf("n=%d    k=%d\n", n, k);
    return 0;
    //int a=2;
    //a=3*5,a*4;
    //printf("%d",a);
    //d=a%2!=0;
    //printf("%d,%d",d,n);
}
