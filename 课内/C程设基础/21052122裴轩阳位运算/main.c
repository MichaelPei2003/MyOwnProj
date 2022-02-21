#include <stdio.h>
#include <stdlib.h>

int getInt()
{
    int n;
    while(!scanf("%d",&n))
    {
        fflush(stdin);
        printf("Error!Enter again...");
    }
    return n;
}

int printBin(int n)
{
    int j=sizeof(int)*8;
    for(int i=0; i<j; i++)
    {
        printf("%d",(n>>j-i-1)&0x1);
        if((i+1)%8==0) printf("   ");
    }
}

void move(int n)
{
    for(int i=1;; i++)
    {
        printf("\n%d向左移动%d位：%d",n,i,n<<i);
        printf("\n%d向右移动%d位：%d",n,i,n>>i);
        getchar();
        if(i==64) break;
    }
}

void decipher(int a,int b)
{
    printf("\n
           解密：密码为：%d，解密得%d",b,a^b);
}

void encrypt()
{
    int n;
    int a=getInt();
    int b=getInt();
    printf("\na=");
    printBin(a);
    printf("\nb=");
    printBin(b);
    printf("\n^=%d",n);
    decipher(n,b);
}

int main(void)
{
    encrypt();
}

