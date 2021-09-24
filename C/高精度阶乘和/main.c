#include<stdio.h>
/*
int main(void)
{
    int a[1010]={0},b[1010]={0},n,j,i;
    scanf("%d",&n);
    a[0]=b[0]=1;
    for(i=2;i<=n;i++)
    {
        for(j=0;j<1000;j++)
        {
            b[j]*=i;
        }
        for(j=0;j<1000;j++)
        {
            if(b[j]>9)
            {
                b[j+1]=b[j]/10;
                b[j]%=10;
            }
        }
        for(j=0;j<1000;j++)
        {
            a[j]+=b[j];
        }
        for(j=0;j<1000;j++)
        {
            if(a[j]>9)
            {
                a[j+1]+=a[j]/10;
                a[j]%=10;
            }
        }
    }
    for(n=1000;n>=0&&a[n]==0;n--)
    {
        continue;
    }
    for(j=n;j>=0;j--)
    {
            printf("%d",a[j]);
    }
}
*/
int main(void)
{
    int a[1010]={0},b[1010]={0},i,j,n;
    scanf("%d",&n);
    a[0]=b[0]=1;
    for(i=2;i<=n;i++)
    {
        for(j=0;j<=1000;j++)
        {
            b[j]*=i;
        }
        for(j=0;j<=1000;j++)
        {
            if(b[j]>9)
            {
                b[j+1]+=b[j]/10;
                b[j]%=10;
            }
        }
        for(j=0;j<=1000;j++)
        {
            a[j]+=b[j];
            if(a[j]>9)
            {
                a[j+1]+=a[j]/10;
                a[j]%=10;
            }
        }
    }
    for(j=1000;j>=0&&a[j]==0;j--);
    for(;j>=0;j--)
    {
        printf("%d",a[j]);
    }
}

/*#include<stdio.h>
int main()
{
    int i,A[105] = {0},B[105] = {0},n,j;
    scanf("%d", &n);
    A[0] = B[0] = 1;
    for (i = 2;i <= n;i++)
    {
        for (j = 0;j < 100;j++)
        {
            B[j] *= i;//开始阶乘但不进位
        }
        for (j = 0;j < 100;j++)
           {
                if (B[j] > 9)
                {
                    B[j + 1] += B[j] / 10;
                    B[j] %=10;
                }//每一位超过9之后把十位数进位给下一位，自己留下个位数
           }
        for (j=0;j< 100;j++)
        {
            A[j] += B[j];//每位A加上对应位的B，即B十位数加给A的十位数，以此类推
            if (A[j] > 9)
            {
                A[j+1] += A[j]/10;//A中进位方式逢十进一
                A[j] %= 10;
            }//阶乘后的加法，A数组相当于sum即所有阶乘之和储存的地方
        }
    }
    for (i = 100;i >= 0 && A[i] == 0;i--);//通过倒序找到A数组已操作的最后一位
    for (j = i;j >= 0;j--) printf("%d", A[j]);//倒序输出，因为AB的储存方式是A[0]对应个位，A[1]对应十位。。。。
    return 0;
}*/
