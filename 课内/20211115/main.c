#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void)
{
    char a[101];
    int i=0,count;
    printf("请输入不超过100字符：");
    while(a[i]=getchar(),a[i]!='\n')
    {
        i++;
    }
    a[i]='\0';
    printf("输入的字符串为：%s\n",a);
    char s16[i];
    int k=0;
    for(int j=0;a[j]!='\0';j++)
    {
        if((a[j]>='0'&&a[j]<='9')||(a[j]>='a'&&a[j]<='f')||(a[j]>='A'&&a[j]<='F'))
        {
            s16[k]=a[j];
            k++;
        }
    }
    s16[k]='\0';
    printf("滤去非16进制数后为：%s\n",s16);
    int num=0,t=0;
    for(i=0;s16[i]!='\0';i++)
    {
        if(s16[i]<='9')
        {
            num=num*16+s16[i]-'0';
        }
        else if(s16[i]>='a'&&s16[i]<='f')
        {
            num=num*16+s16[i]-'a'+10;
        }
        else
        {
            num=num*16+s16[i]-'A'+10;
        }
    }
    printf("%d",num);
}
