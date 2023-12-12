#include <bits/stdc++.h>

using namespace std;

double calculate(float a,float b,float c,float d);

int main(void)
{
    float x1,y1,x2,y2,x3,y3,s1,s2,s3,s;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    s1=calculate(x1,y1,x2,y2);
    s2=calculate(x1,y1,x3,y3);
    s3=calculate(x2,y2,x3,y3);
    s=s1+s2+s3;
    cout<<fixed<<setprecision(2)<<s;
}

double calculate(float a,float b,float c,float d)
{
    float s,x,y;
    x=pow(c-a,2);
    y=pow(d-b,2);
    s=sqrt(x+y);
    return s;
}
