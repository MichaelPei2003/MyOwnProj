#include <bits/stdc++.h>
#define PI 3.14

using namespace std;

struct point
{
    double x;
    double y;
    double z;
};//此处分号勿忘！

//直接对字符串数组赋值：strcpy(a,"111111");其中，char a

/*int main(int argc, char *argv[])
{
    //动态内存分配
    int *p,n;
    while(n!=888)
    {
        printf("\n请输入空间大小，输入888退出：");
        struct point a={1.0,2.0,3.0};
        while(!scanf("%d",&n)||n<1)
        {
            fflush(stdin);
            printf("无效输入！");
        }
        //int a[n] 此语法在C中不可使用
        p=(int*)malloc(n*sizeof(int));//分配100*sizeof(int)长度的内存
        if(p==NULL)
        {
            printf("内存分配失败！");
            exit(1);//通识：程序正常运行时返回0，不正常时返回非零
        }
        else
        {
            printf("内存分配成功！\n");
        }
        for(int i=0; i<n; i++)
        {
            *(p+i)=i;
        }
        for(int i=0; i<n; i++)
        {
            printf("%5d ",*(p+i));
        }
        free(p);//释放分配给p的内存
    }
    return 0;
}
*/

struct circle
{
    float r;
    float d;
    float c;
    float s;
};

int main(void)
{
    struct circle a;
    cout<<"R=";
    cin>>a.r;
    a.d=2*a.r;
    a.c=2*PI*a.r;
    a.s=PI*a.r*a.r;
    printf("\n园的半径为%f，直径为%f，周长为%f，面积为%f",a.r,a.d,a.c,a.s);
}
