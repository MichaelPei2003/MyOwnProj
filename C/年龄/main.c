#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a=55;
    if(a<18)
    {
        printf("青少年");
    }
    else if(a>18&&a<45)
    {
        printf("青壮年");
    }
    else if(a>45&&a<65)
    {
        printf("中年人");
    }
    else
    {
        printf("老年人");
    }
}
