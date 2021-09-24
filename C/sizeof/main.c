#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    short b;
    long c;
    char d;
    float e;
    double f;
    printf("the size of int is:%d\n",sizeof(a));
    printf("the size of short is:%d\n",sizeof(b));
    printf("the size of long is:%d\n",sizeof(c));
    printf("the size of char is:%d\n",sizeof(d));
    printf("the size of float is:%d\n",sizeof(e));
    printf("the size of double is:%d",sizeof(f));
    return 0;
}
