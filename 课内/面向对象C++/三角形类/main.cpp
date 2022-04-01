#include <iostream>
#include <cmath>

using namespace std;

class triangle
{
    float m_x1, m_y1, m_x2, m_y2, m_x3, m_y3;
public:
    void Store(float x1, float y1, float x2, float y2, float x3, float y3);
    void Calculate() const;
};

void triangle::Store(float x1,float y1, float x2, float y2, float x3, float y3)
{
    m_x1=x1;
    m_x2=x2;
    m_x3=x3;
    m_y1=y1;
    m_y2=y2;
    m_y3=y3;
}

void triangle::Calculate() const
{
    float l1, l2, l3, c;
    l1=sqrt(pow(m_x1-m_x2, 2) + pow(m_y1-m_y2, 2));
    l2=sqrt(pow(m_x3-m_x2, 2) + pow(m_y3-m_y2, 2));
    l3=sqrt(pow(m_x1-m_x3, 2) + pow(m_y1-m_y3, 2));
    c=l1+l2+l3;
    cout<<c;
}

int main()
{
    triangle triangle1;
    float x1, y1, x2, y2, x3, y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    triangle1.Store(x1,y1,x2,y2,x3,y3);
    triangle1.Calculate();
}
