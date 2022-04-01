#include <iostream>
#include <iomanip>
#define PI 3.1415926

using namespace std;

class Circle
{
    float m_r;
public:
    void Store(float r);
    void Calculate() const;
};

void Circle::Store(float r)
{
    m_r=r;
}

void Circle::Calculate() const
{
    float c, s;
    int tmp;
    c=2*PI*m_r*35;
    s=PI*m_r*m_r*20;
    cout<<fixed<<setprecision(2)<<s+c;
}

int main()
{
    Circle circle1;
    float r;
    cin>>r;
    circle1.Store(r);
    circle1.Calculate();
}
