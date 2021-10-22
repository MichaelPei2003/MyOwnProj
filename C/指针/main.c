#include <stdio.h>

int main()
{
    int x;
    int *a;
    a=&x;
    printf("%#x",a);
    scanf("%d",&x);
    printf("\n%d",*a);
}
