#include <stdio.h>

int main(void)
{
    double a,b;
    //aΪ�õ�����bΪ���
    scanf("%lf",&a);
    if(a<0){printf("Invalid Value!");exit(0);}
    else if(a<=50){b=a*0.53;}
    else {b=26.5+(a-50)*0.58;}
    printf("cost = %.2lf",b);
}
