#include <iostream>
using namespace std;
#include "CClock.h"

void CClock::ShowTime () const
{
    cout << m_iHour<< ":" << m_iMinute<< ":" <<m_iSecond << endl;
}

int main ()
{
    CClock  t1, t2;

    t1.SetTime(10,20,30);
    t2.SetTime(11,10,25);
    t1.ShowTime();
    t2.ShowTime();
}
