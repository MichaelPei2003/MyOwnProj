#include <bits/stdc++.h>

using namespace std;

/*int main(void)
{
    int a=1;
    cout<<"����a��ֵΪ"<<a<<endl<<"����a�ĵ�ַΪ"<<&a<<endl;
    printf("a��ֵΪ��%d\na�ĵ�ַΪ��%d\n",a,&a);
    int *pa,*pb;
    pa=&a;
    printf("a��ֵΪ��%d\na�ĵ�ַΪ��%p\n",*pa,pa);
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
//p1��p2Ϊx1��x2�ĵ�ַ
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
