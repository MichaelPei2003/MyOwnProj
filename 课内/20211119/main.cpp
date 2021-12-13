#include <bits/stdc++.h>

using namespace std;

/*int main(void)
{
    int a=1;
    cout<<"变量a的值为"<<a<<endl<<"变量a的地址为"<<&a<<endl;
    printf("a的值为：%d\na的地址为：%d\n",a,&a);
    int *pa,*pb;
    pa=&a;
    printf("a的值为：%d\na的地址为：%p\n",*pa,pa);
}
*/

/*int main(void)
{
    int a,b,tmp;
    int *pa,*pb;
    pa=&a;
    pb=&b;
    cin>>a>>b;
    cout<<&a<<" "<<&b<<endl;
    pa=&a;
    pb=&b;
    tmp=*pa;
    *pa=*pb;
    *pb=tmp;
    cout<<a<<" "<<b<<endl;
    cout<<&a<<" "<<&b;
}
*/
int root(double a,double b,double c,double *p1,double *p2)
//p1，p2为x1，x2的地址
{
    double d;
    d=b*b-4*a*c;
    if(d<0){return 0;}
    else
    {
        *p1=(-b+sqrt(d))/(2*a);
        *p2=(-b-sqrt(d))/(2*a);
        return 1;
    }
}

int main(void)
{
    double a,b,c,x1,x2;
    int flag;
    cout<<"ax^2+bx+c=0"<<endl;
    cout<<"a=";
    cin>>a;
    cout<<"b=";
    cin>>b;
    cout<<"c=";
    cin>>c;
    flag=root(a,b,c,&x1,&x2);
    if(flag==0){cout<<"No real roots.";exit(0);}
    else
    {
        printf("x1=%.2lf x2=%.2lf",x1,x2);
    }
}
